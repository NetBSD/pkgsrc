#!@BUILDLINK_SHELL@
#
# $NetBSD: wrapper.sh,v 1.10 2004/01/30 10:56:11 jlam Exp $

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

updatecache="${BUILDLINK_UPDATE_CACHE-yes}"
cacheall="${BUILDLINK_CACHE_ALL-no}"
reorder="${BUILDLINK_REORDER-no}"

cat="@CAT@"
echo="@ECHO@"
expr="@EXPR@"
test="@TEST@"

BUILDLINK_DIR="@BUILDLINK_DIR@"
WRKDIR="@WRKDIR@"
WRKSRC="@WRKSRC@"

# Argument stack depth
depth=

original_cmd="$0 $@"
$echo [*] $original_cmd >> $wrapperlog

cmd="@WRAPPEE@"
ldflags=
libs=
set -- "$@" @_BLNK_WRAP_EXTRA_FLAGS@
while $test $# -gt 0 -o -n "$depth"; do
	cachehit=no
	skipcache=no
	skipargs=0
	#
	# Get the next argument from the buffer.
	#
	. $buffer
	#
	# Check the private cache, and possibly set skipcache=yes.
	#
	. $private_cache
	#
	# Check the common cache shared by all of the other wrappers.
	#
	case $skipcache,$cachehit in
	no,no)	. $cache ;;
	esac
	#
	# If the cache doesn't cover the arg we're examining, then
	# run it through the transformations and cache the result.
	#
	case $cachehit in
	no)	. $logic ;;
	esac
	#
	# Build up the command-line.
	#
	. $buildcmd
done

# Reorder the libraries so that the library dependencies are correct.
case $reorder in
yes)
	. $reorderlibs
	;;
esac

cmd="$cmd $ldflags $libs"

@_BLNK_WRAP_ENV@
@_BLNK_WRAP_SANITIZE_PATH@

$echo "<.>" $cmd >> $wrapperlog
eval exec $cmd
