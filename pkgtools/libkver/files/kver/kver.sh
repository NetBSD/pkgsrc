#!@SH@

LIBKVER='@PREFIX@/lib/libkver.so'
EX_USAGE=64
nl='
'
tab='	'

usage()
{
	cat <<ENDUSAGE;
usage: $0 [-s ostype] [-r osrelease] [-m machine] [-p arch] command [args]
ENDUSAGE
}

bomb()
{
	echo >&2 "$0: $*"
	exit $EX_USAGE
}

# begin code copied from build.sh {{{

# valid_MACHINE_ARCH -- A multi-line string, listing all valid
# MACHINE/MACHINE_ARCH pairs.
#
# Each line contains a MACHINE and MACHINE_ARCH value, an optional ALIAS
# which may be used to refer to the MACHINE/MACHINE_ARCH pair, and an
# optional DEFAULT or NO_DEFAULT keyword.
#
# When a MACHINE corresponds to multiple possible values of
# MACHINE_ARCH, then this table should list all allowed combinations.
# If the MACHINE is associated with a default MACHINE_ARCH (to be
# used when the user specifies the MACHINE but fails to specify the
# MACHINE_ARCH), then one of the lines should have the "DEFAULT"
# keyword.  If there is no default MACHINE_ARCH for a particular
# MACHINE, then there should be a line with the "NO_DEFAULT" keyword,
# and with a blank MACHINE_ARCH.
#
valid_MACHINE_ARCH='
MACHINE=acorn26		MACHINE_ARCH=arm
MACHINE=acorn32		MACHINE_ARCH=arm
MACHINE=algor		MACHINE_ARCH=mips64el	ALIAS=algor64
MACHINE=algor		MACHINE_ARCH=mipsel	DEFAULT
MACHINE=alpha		MACHINE_ARCH=alpha
MACHINE=amd64		MACHINE_ARCH=x86_64
MACHINE=amiga		MACHINE_ARCH=m68k
MACHINE=amigappc	MACHINE_ARCH=powerpc
MACHINE=arc		MACHINE_ARCH=mips64el	ALIAS=arc64
MACHINE=arc		MACHINE_ARCH=mipsel	DEFAULT
MACHINE=atari		MACHINE_ARCH=m68k
MACHINE=bebox		MACHINE_ARCH=powerpc
MACHINE=cats		MACHINE_ARCH=arm	DEFAULT
MACHINE=cats		MACHINE_ARCH=earmv4	ALIAS=ecats
MACHINE=cesfic		MACHINE_ARCH=m68k
MACHINE=cobalt		MACHINE_ARCH=mips64el	ALIAS=cobalt64
MACHINE=cobalt		MACHINE_ARCH=mipsel	DEFAULT
MACHINE=dreamcast	MACHINE_ARCH=sh3el
MACHINE=emips		MACHINE_ARCH=mipseb
MACHINE=epoc32		MACHINE_ARCH=arm
MACHINE=evbarm		MACHINE_ARCH=arm	ALIAS=evbarm-el	DEFAULT
MACHINE=evbarm		MACHINE_ARCH=armeb	ALIAS=evbarm-eb
MACHINE=evbarm		MACHINE_ARCH=earm	ALIAS=evbearm-el
MACHINE=evbarm		MACHINE_ARCH=earmeb	ALIAS=evbearm-eb
MACHINE=evbarm		MACHINE_ARCH=earmhf	ALIAS=evbearmhf-el
MACHINE=evbarm		MACHINE_ARCH=earmhfeb	ALIAS=evbearmhf-eb
MACHINE=evbarm		MACHINE_ARCH=earmv4	ALIAS=evbearmv4-el
MACHINE=evbarm		MACHINE_ARCH=earmv4eb	ALIAS=evbearmv4-eb
MACHINE=evbarm		MACHINE_ARCH=earmv5	ALIAS=evbearmv5-el
MACHINE=evbarm		MACHINE_ARCH=earmv5eb	ALIAS=evbearmv5-eb
MACHINE=evbarm		MACHINE_ARCH=earmv6	ALIAS=evbearmv6-el
MACHINE=evbarm		MACHINE_ARCH=earmv6hf	ALIAS=evbearmv6hf-el
MACHINE=evbarm		MACHINE_ARCH=earmv6eb	ALIAS=evbearmv6-eb
MACHINE=evbarm		MACHINE_ARCH=earmv6hfeb	ALIAS=evbearmv6hf-eb
MACHINE=evbarm		MACHINE_ARCH=earmv7	ALIAS=evbearmv7-el
MACHINE=evbarm		MACHINE_ARCH=earmv7eb	ALIAS=evbearmv7-eb
MACHINE=evbarm		MACHINE_ARCH=earmv7hf	ALIAS=evbearmv7hf-el
MACHINE=evbarm		MACHINE_ARCH=earmv7hfeb	ALIAS=evbearmv7hf-eb
MACHINE=evbcf		MACHINE_ARCH=coldfire
MACHINE=evbmips		MACHINE_ARCH=		NO_DEFAULT
MACHINE=evbmips		MACHINE_ARCH=mips64eb	ALIAS=evbmips64-eb
MACHINE=evbmips		MACHINE_ARCH=mips64el	ALIAS=evbmips64-el
MACHINE=evbmips		MACHINE_ARCH=mipseb	ALIAS=evbmips-eb
MACHINE=evbmips		MACHINE_ARCH=mipsel	ALIAS=evbmips-el
MACHINE=evbppc		MACHINE_ARCH=powerpc	DEFAULT
MACHINE=evbppc		MACHINE_ARCH=powerpc64	ALIAS=evbppc64
MACHINE=evbsh3		MACHINE_ARCH=		NO_DEFAULT
MACHINE=evbsh3		MACHINE_ARCH=sh3eb	ALIAS=evbsh3-eb
MACHINE=evbsh3		MACHINE_ARCH=sh3el	ALIAS=evbsh3-el
MACHINE=ews4800mips	MACHINE_ARCH=mipseb
MACHINE=hp300		MACHINE_ARCH=m68k
MACHINE=hp700		MACHINE_ARCH=hppa
MACHINE=hpcarm		MACHINE_ARCH=arm	DEFAULT
MACHINE=hpcarm		MACHINE_ARCH=earm	ALIAS=hpcearm
MACHINE=hpcmips		MACHINE_ARCH=mipsel
MACHINE=hpcsh		MACHINE_ARCH=sh3el
MACHINE=i386		MACHINE_ARCH=i386
MACHINE=ia64		MACHINE_ARCH=ia64
MACHINE=ibmnws		MACHINE_ARCH=powerpc
MACHINE=iyonix		MACHINE_ARCH=arm	DEFAULT
MACHINE=iyonix		MACHINE_ARCH=earm	ALIAS=eiyonix
MACHINE=landisk		MACHINE_ARCH=sh3el
MACHINE=luna68k		MACHINE_ARCH=m68k
MACHINE=mac68k		MACHINE_ARCH=m68k
MACHINE=macppc		MACHINE_ARCH=powerpc	DEFAULT
MACHINE=macppc		MACHINE_ARCH=powerpc64	ALIAS=macppc64
MACHINE=mipsco		MACHINE_ARCH=mipseb
MACHINE=mmeye		MACHINE_ARCH=sh3eb
MACHINE=mvme68k		MACHINE_ARCH=m68k
MACHINE=mvmeppc		MACHINE_ARCH=powerpc
MACHINE=netwinder	MACHINE_ARCH=arm	DEFAULT
MACHINE=netwinder	MACHINE_ARCH=earmv4	ALIAS=enetwinder
MACHINE=news68k		MACHINE_ARCH=m68k
MACHINE=newsmips	MACHINE_ARCH=mipseb
MACHINE=next68k		MACHINE_ARCH=m68k
MACHINE=ofppc		MACHINE_ARCH=powerpc	DEFAULT
MACHINE=ofppc		MACHINE_ARCH=powerpc64	ALIAS=ofppc64
MACHINE=pmax		MACHINE_ARCH=mips64el	ALIAS=pmax64
MACHINE=pmax		MACHINE_ARCH=mipsel	DEFAULT
MACHINE=prep		MACHINE_ARCH=powerpc
MACHINE=rs6000		MACHINE_ARCH=powerpc
MACHINE=sandpoint	MACHINE_ARCH=powerpc
MACHINE=sbmips		MACHINE_ARCH=		NO_DEFAULT
MACHINE=sbmips		MACHINE_ARCH=mips64eb	ALIAS=sbmips64-eb
MACHINE=sbmips		MACHINE_ARCH=mips64el	ALIAS=sbmips64-el
MACHINE=sbmips		MACHINE_ARCH=mipseb	ALIAS=sbmips-eb
MACHINE=sbmips		MACHINE_ARCH=mipsel	ALIAS=sbmips-el
MACHINE=sgimips		MACHINE_ARCH=mips64eb	ALIAS=sgimips64
MACHINE=sgimips		MACHINE_ARCH=mipseb	DEFAULT
MACHINE=shark		MACHINE_ARCH=arm	DEFAULT
MACHINE=shark		MACHINE_ARCH=earmv4	ALIAS=eshark
MACHINE=sparc		MACHINE_ARCH=sparc
MACHINE=sparc64		MACHINE_ARCH=sparc64
MACHINE=sun2		MACHINE_ARCH=m68000
MACHINE=sun3		MACHINE_ARCH=m68k
MACHINE=vax		MACHINE_ARCH=vax
MACHINE=x68k		MACHINE_ARCH=m68k
MACHINE=zaurus		MACHINE_ARCH=arm	DEFAULT
MACHINE=zaurus		MACHINE_ARCH=earm	ALIAS=ezaurus
'

# getarch -- find the default MACHINE_ARCH for a MACHINE,
# or convert an alias to a MACHINE/MACHINE_ARCH pair.
#
# Saves MACHINE in makewrappermachine before possibly modifying MACHINE.
#
# Sets MACHINE and MACHINE_ARCH if the input MACHINE value is
# recognised as an alias, or recognised as a machine that has a default
# MACHINE_ARCH (or that has only one possible MACHINE_ARCH).
#
# Leaves MACHINE and MACHINE_ARCH unchanged if MACHINE is recognised
# as being associated with multiple MACHINE_ARCH values with no default.
#
# Bombs if MACHINE is not recognised.
#
getarch()
{
	local IFS
	local found=""
	local line

	IFS="${nl}"
	makewrappermachine="${MACHINE}"
	for line in ${valid_MACHINE_ARCH}; do
		line="${line%%#*}" # ignore comments
		line="$( IFS=" ${tab}" ; echo $line )" # normalise white space
		case "${line} " in
		"")
			# skip blank lines or comment lines
			continue
			;;
		*" ALIAS=${MACHINE} "*)
			# Found a line with a matching ALIAS=<alias>.
			found="$line"
			break
			;;
		"MACHINE=${MACHINE} "*" NO_DEFAULT"*)
			# Found an explicit "NO_DEFAULT" for this MACHINE.
			found="$line"
			break
			;;
		"MACHINE=${MACHINE} "*" DEFAULT"*)
			# Found an explicit "DEFAULT" for this MACHINE.
			found="$line"
			break
			;;
		"MACHINE=${MACHINE} "*)
			# Found a line for this MACHINE.  If it's the
			# first such line, then tentatively accept it.
			# If it's not the first matching line, then
			# remember that there was more than one match.
			case "$found" in
			'')	found="$line" ;;
			*)	found="MULTIPLE_MATCHES" ; break ;;
			esac
			;;
		esac
	done

	case "$found" in
	*NO_DEFAULT*|*MULTIPLE_MATCHES*)
		# MACHINE is OK, but MACHINE_ARCH is still unknown
		return
		;;
	"MACHINE="*" MACHINE_ARCH="*)
		# Obey the MACHINE= and MACHINE_ARCH= parts of the line.
		IFS=" "
		for frag in ${found}; do
			case "$frag" in
			MACHINE=*|MACHINE_ARCH=*)
				eval "$frag"
				;;
			esac
		done
		;;
	*)
		bomb "Unknown target MACHINE: ${MACHINE}"
		;;
	esac
}

# end code copied from build.sh }}}


# MAIN PROGRAM

opt_s=""
opt_r=""
opt_m=""
opt_p=""

while getopts "s:r:m:p:" opt
do
	case "$opt" in
	s) opt_s="$OPTARG"; export LIBKVER_OSTYPE="$OPTARG" ;;
	r) opt_r="$OPTARG"; export LIBKVER_OSRELEASE="$OPTARG" ;;
	m) opt_m="$OPTARG"; export LIBKVER_MACHINE="$OPTARG" ;;
	p) opt_p="$OPTARG"; export LIBKVER_MACHINE_ARCH="$OPTARG" ;;
	*) usage ; exit $EX_USAGE ;;
	esac
done
shift $(($OPTIND - 1))
if [ $# -eq 0 ]; then
	usage
	exit $EX_USAGE
fi

# If MACHINE was specified and MACHINE_ARCH was not specified,
# then try to guess MACHINE_ARCH.
if [ -n "$opt_m" ] && [ -z "$opt_p" ]; then
	MACHINE="$opt_m"
	getarch
	if [ -n "$MACHINE_ARCH" ]; then
		# in addition to setting MACHINE_ARCH,
		# getarch might have modified MACHINE.
		export LIBKVER_MACHINE="$MACHINE"
		export LIBKVER_MACHINE_ARCH="$MACHINE_ARCH"
	else
		bomb "'-m ${MACHINE}' needs '-p <machine_arch>'"
	fi
fi

export LD_PRELOAD="${LIBKVER}${LD_PRELOAD:+:}${LD_PRELOAD}"
exec "$@"
