#!@BUILDLINK_SHELL@
#
# $NetBSD: wrapper.sh,v 1.7.4.2 2003/01/01 07:16:58 jlam Exp $

Xsed='@SED@ -e 1s/^X//'
sed_quote_subst='s/\([\\`\\"$\\\\]\)/\\\1/g'

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
wrapperlog="@_BLNK_WRAP_LOG@"

updatecache=${BUILDLINK_UPDATE_CACHE-yes}
cacheall=${BUILDLINK_CACHE_ALL-no}

cat="@CAT@"
echo="@ECHO@"
test="@TEST@"

BUILDLINK_DIR="@BUILDLINK_DIR@"
BUILDLINK_X11_DIR="@BUILDLINK_X11_DIR@"
WRKDIR="@WRKDIR@"
WRKSRC="@WRKSRC@"

cmd="@WRAPPEE@"
while $test $# -gt 0; do
	arg="$1"; shift
	cachehit=no
	skipcache=no
	. $private_cache
	case $skipcache,$cachehit in
	no,no)	. $cache ;;
	esac
	case $cachehit in
	no)	. $logic ;;
	esac
	cmd="$cmd $arg"
done

@_BLNK_WRAP_ENV@
@_BLNK_WRAP_SANITIZE_PATH@

$echo $cmd >> $wrapperlog
eval exec $cmd
