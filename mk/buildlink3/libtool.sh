#!@BUILDLINK_SHELL@
#
# $NetBSD: libtool.sh,v 1.4 2003/09/23 19:48:23 jlam Exp $

Xsed='@SED@ -e 1s/^X//'
sed_quote_subst='s/\([\\`\\"$\\\\]\)/\\\1/g'

marshall="@_BLNK_WRAP_MARSHALL@"
private_pre_cache="@_BLNK_WRAP_PRIVATE_PRE_CACHE@"
private_cache_add="@_BLNK_WRAP_PRIVATE_CACHE_ADD@"
private_cache="@_BLNK_WRAP_PRIVATE_CACHE@"
private_post_cache="@_BLNK_WRAP_PRIVATE_POST_CACHE@"
pre_cache="@_BLNK_WRAP_PRE_CACHE@"
cache_add="@_BLNK_WRAP_CACHE_ADD@"
cache="@_BLNK_WRAP_CACHE@"
post_cache="@_BLNK_WRAP_POST_CACHE@"
logic="@_BLNK_WRAP_LOGIC@"
post_logic="@_BLNK_WRAP_POST_LOGIC@"

wrapperlog="${BUILDLINK_WRAPPER_LOG-@_BLNK_WRAP_LOG@}"

libtool_fix_la="@_BLNK_LIBTOOL_FIX_LA@"
libtool_do_install="@_BLNK_LIBTOOL_DO_INSTALL@"
fixlibpath=${BUILDLINK_FIX_IMPROPER_LIBTOOL_LIBPATH-yes}

updatecache=${BUILDLINK_UPDATE_CACHE-yes}
cacheall=${BUILDLINK_CACHE_ALL-no}

cat="@CAT@"
echo="@ECHO@"
test="@TEST@"

BUILDLINK_DIR="@BUILDLINK_DIR@"
WRKDIR="@WRKDIR@"
WRKSRC="@WRKSRC@"

mode=link
prevopt=
nonopt=
lafile=
for arg; do
	case $arg in
	-*=*)	optarg=`$echo "X$arg" | $Xsed -e 's/[-_a-zA-Z0-9]*=//'` ;;
	*)	optarg= ;;
	esac
	if $test -n "$prevopt"; then
		case $prevopt in
		--mode)
			mode="$arg"
			;;
		--fix-la|-o)
			case $arg in
			*.la) lafile="$arg" ;;
			esac
			;;
		esac
		prevopt=
		continue
	fi
	case $arg in
	--mode|--fix-la|-o)
		prevopt="$arg"
		;;
	--mode=*)
		mode="$optarg"
		;;
	-*)
		if $test -n "$nonopt"; then
			case $arg in
			-c) mode=compile ;;
			esac
		fi
		;;
	*)
		if $test -z "$nonopt"; then	
			nonopt="$arg"
			case $arg in
			*cc|*++|gcc*|*-gcc*|*CC) mode=link ;;
			*install*|cp|mv)	 mode=install ;;
			esac
		fi
		;;
	esac
done

cmd="@WRAPPEE@"
case $mode in
install)
	arg="$1"; shift
	. $libtool_do_install
	;;
*)
	while $test $# -gt 0; do
		arg="$1"; shift
		case $arg in
		--fix-la)
			. $libtool_fix_la
			exit
			;;
		*cc|*++|gcc*|*-gcc*|*CC)
			case $mode in
			link)
				cmd="$cmd $arg"
 				arg="@_BLNK_WRAP_EXTRA_FLAGS@"
				;;
			esac
			;;
		*)
			cachehit=no
			skipcache=no
			#
			# Marshall any group of consecutive arguments into
			# a single $arg to be checked in the cache and
			# logic files.
			#
			. $marshall
			#
			# Check the private cache, and possibly set
			# skipcache=yes.
			#
			. $private_cache
			#
			# Check the common cache shared by all of the other
			# wrappers.
			#
			case $skipcache,$cachehit in
			no,no)	. $cache ;;
			esac
			#
			# If the cache doesn't cover the arg we're
			# examining, then run it through the
			# transformations and cache the result.
			#
			case $cachehit in
			no)	. $logic ;;
			esac
			;;
		esac
		#
		# Reduce command length by not appending options that we've
		# already seen to the command.
		#
		case "$arg" in
		-[DILR]*|-Wl,-R*|-Wl,-*,/*)
			#
			# These options are only ever useful the first time
			# they're given.  All other instances are redundant.
			#
			case "$cmd" in
			*" "$arg|*" "$arg" "*)  ;;
			*)      cmd="$cmd $arg" ;;
			esac
			;;
		-l*)
			#
			# Extra libraries are suppressed only if they're
			# repeated, e.g. "-lm -lm -lm -lm" -> "-lm".
			#
			case "$cmd" in
			*" "$arg)       ;;
			*)      cmd="$cmd $arg" ;;
			esac
			;;
		*)
			cmd="$cmd $arg"
			;;
		esac
	done
	;;
esac

@_BLNK_WRAP_ENV@
@_BLNK_WRAP_SANITIZE_PATH@

$echo $cmd >> $wrapperlog
eval $cmd
wrapper_result=$?

if $test -n "$lafile" && $test -f "$lafile"; then
	. $libtool_fix_la
fi

exit ${wrapper_result}
