#!@BUILDLINK_SHELL@
#
# $NetBSD: libtool.sh,v 1.17 2004/03/30 17:25:19 jlam Exp $

Xsed='@SED@ -e 1s/^X//'
sed_quote_subst='s/\([\\`\\"$\\\\]\)/\\\1/g'

buildcmd="@_BLNK_WRAP_BUILDCMD@"
quotearg="@_BLNK_WRAP_QUOTEARG@"
buffer="@_BLNK_WRAP_BUFFER@"
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
reorderlibs="@_BLNK_REORDERLIBS@"

wrapperlog="${BUILDLINK_WRAPPER_LOG-@_BLNK_WRAP_LOG@}"

libtool_fix_la="@_BLNK_LIBTOOL_FIX_LA@"
fixlibpath=${BUILDLINK_FIX_IMPROPER_LIBTOOL_LIBPATH-yes}

updatecache="${BUILDLINK_UPDATE_CACHE-yes}"
cacheall="${BUILDLINK_CACHE_ALL-no}"
reorder="${BUILDLINK_REORDER-no}"

basename="@BASENAME@"
cat="@CAT@"
dirname="@DIRNAME@"
echo="@ECHO@"
expr="@EXPR@"
pwd="@PWD_CMD@"
test="@TEST@"

BUILDLINK_DIR="@BUILDLINK_DIR@"
WRKDIR="@WRKDIR@"
WRKSRC="@WRKSRC@"

# Argument stack depth
depth=

original_cmd="$0 $@"
$echo [*] $original_cmd >> $wrapperlog

# Discover the libtool mode by examining the argument list.
mode=link
prevopt=
nonopt=
lafile=
for arg do
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
		if $test -n "$nonopt" -a "$mode" != "install"; then
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
ldflags=
libs=
case $mode in
install)
	#
	# We're doing libtool installation, so just quote all of the
	# command-line arguments and append them to $cmd.  We don't worry
	# about caching or speed, since installation is not a bottleneck
	# for package creation.
	#
	while $test $# -gt 0; do
		arg="$1"; shift
		. $quotearg
		arg="$qarg"
		cmd="$cmd $arg"
	done    
	;;
*)
	while $test $# -gt 0 -o -n "$depth"; do
		skipargs=0
		#
		# Get the next argument from the buffer.
		#
		. $buffer

		case $arg in
		--fix-la)
			. $libtool_fix_la
			exit
			;;
		*cc|*++|gcc*|*-gcc*|*CC)
			case $mode in
			link)
				set -- "$@" @_BLNK_WRAP_EXTRA_FLAGS@
				;;
			esac
			;;
		*)
			cachehit=no
			skipcache=no
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
		# Build up the command-line.
		#
		. $buildcmd
	done
	;;
esac

# Reorder the libraries so that the library dependencies are correct.
case $reorder in
yes)
	if $test -n "$libs"; then
		. $reorderlibs
	fi
	;;
esac

cmd="$cmd $ldflags $libs"

@_BLNK_WRAP_ENV@
@_BLNK_WRAP_SANITIZE_PATH@

$echo "<.>" $cmd >> $wrapperlog
eval $cmd
wrapper_result=$?

if $test -n "$lafile" && $test -f "$lafile"; then
	. $libtool_fix_la
fi

exit ${wrapper_result}
