#!@BUILDLINK_SHELL@
#
# $NetBSD: wrapper.sh,v 1.5 2002/12/22 19:02:45 jlam Exp $

Xsed='@SED@ -e 1s/^X//'
sed_quote_subst='s/\([\\`\\"$\\\\]\)/\\\1/g'

pre_cache="@_BLNK_WRAP_PRE_CACHE@"
cache="@_BLNK_WRAP_CACHE@"
post_cache="@_BLNK_WRAP_POST_CACHE@"
logic="@_BLNK_WRAP_LOGIC@"
specificlogic="@_BLNK_WRAP_SPECIFIC_LOGIC@"
wrapperlog="@_BLNK_WRAP_LOG@"
updatecache=${BUILDLINK_UPDATE_CACHE-yes}
cacheall=${BUILDLINK_CACHE_ALL-no}

cmd="@WRAPPEE@"
for arg do
	cacheupdated=no
	. $logic
	case "$cacheupdated" in
	yes) @CAT@ $pre_cache $cache $post_cache > $logic ;;
	esac
	. $specificlogic
	cmd="$cmd $arg"
done

@_BLNK_WRAP_ENV@
@_BLNK_WRAP_SANITIZE_PATH@

@ECHO@ $cmd >> $wrapperlog
eval exec $cmd
