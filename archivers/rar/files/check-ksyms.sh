#!/bin/sh
#
# $NetBSD: check-ksyms.sh,v 1.1 2007/08/22 16:43:36 jlam Exp $
#
# check-ksyms.sh verifies that the given symbols are found in the booted
# kernel file.
#

: ${ECHO=echo}
: ${GREP=grep}
: ${GZIP_CMD=gzip}
: ${NM=nm}
: ${RM=rm}
: ${TMPDIR=/tmp}

self="check-ksyms"

verbose=
while [ $# -gt 0 ]; do
	case $1 in
	-v)	verbose=yes; shift ;;
	--)	shift; break ;;
	-*)	${ECHO} 1>&2 "$self [-v] symbol ..."; exit 2 ;;
	*)	break ;;
	esac
done

# Locate kernel.
PATH=/sbin:/usr/sbin:${PATH}; export PATH

booted_kernel=
kernlist="/netbsd /netbsd.gz /onetbsd /onetbsd.gz"
kern=`sysctl -n machdep.booted_kernel 2>/dev/null`
if [ -z "$kern" ]; then
	kernlist="$kern $kernlist"
fi
for k in $kernlist; do
	if [ -f "$k" ]; then
		booted_kernel="$k"
		break
	fi
done

if [ -z "$booted_kernel" ]; then
	${ECHO} 1>&2 "$self: could not determine the booted kernel."
	exit 2
fi

pattern=
for symbol	# in command-line arguments
do
	if [ -z "$pattern" ]; then
		pattern="$symbol"
	else
		pattern="$pattern\|$symbol"
	fi
done

# If there are no symbols to check, then exit with success.
[ -n "$pattern" ] || exit 0

if [ ! -d "${TMPDIR}" ]; then
	${ECHO} 1>&2 "$self: ${TMPDIR} does not exist."
	exit 2
fi

ksymsfile="${TMPDIR}/ksyms.$self.$$"

# Clean up when we receive the following signals: INT QUIT ABRT KILL TERM.
trap "${RM} -f \"$ksymsfile\"" 2 3 6 9 15

case $booted_kernel in
*.gz)	${GZIP_CMD} -d < "$booted_kernel" | ${NM} > "$ksymsfile" ;;
*)	${NM} "$booted_kernel" > "$ksymsfile" ;;
esac

# Loop through the symbols and check that each of them are in $ksymsfile.
exitcode=0
while [ $# -gt 0 ]; do
	symbol="$1"; shift
	if [ x"$verbose" = xyes ]; then
		cmd="${GREP} \"$symbol\" \"$ksymsfile\" 2>/dev/null"
	else
		cmd="${GREP} \"$symbol\" \"$ksymsfile\" >/dev/null 2>&1"
	fi
	if eval $cmd; then
		:
	else
		${ECHO} 1>&2 "$self: symbol $symbol not found in $booted_kernel"
		exitcode=1
		break
	fi
done

${RM} -f "$ksymsfile"
exit $exitcode
