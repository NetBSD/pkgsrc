#!@BUILDLINK_SHELL@
#
# $NetBSD: libtool.sh,v 1.3 2002/09/16 19:06:41 jlam Exp $

Xsed='@SED@ -e 1s/^X//'
sed_quote_subst='s/\([\\`\\"$\\\\]\)/\\\1/g'

pre_cache="@_BLNK_WRAP_PRE_CACHE@"
cache="@_BLNK_WRAP_CACHE@"
post_cache="@_BLNK_WRAP_POST_CACHE@"
logic="@_BLNK_WRAP_LOGIC@"
libtool_fix_la="@_BLNK_LIBTOOL_FIX_LA@"
wrapperlog="@_BLNK_WRAP_LOG@"
updatecache=${BUILDLINK_UPDATE_CACHE-yes}

cmd="@WRAPPEE@"
lafile=
while [ $# -gt 0 ]; do
	arg="$1"; shift
	case $arg in
	--fix-la)
		case "$1" in
		*.la)
			lafile="$1"
		 	. $libtool_fix_la
			exit
			;;
		esac
		;;
	--mode|--mode=install)
		if [ "$arg" = "--mode=install" ] || \
		   [ "$arg" = "--mode" -a "$1" = "install" ]; then
			args="$args $arg"
			while [ $# -gt 0 ]; do
				arg="$1"; shift
				case $arg in
				*[\`\"\$\\]*)
					arg=`@ECHO@ X$arg | \
						$Xsed -e "$sed_quote_subst" \
					`
					;;
				esac
				case $arg in
				*[\[\~\#\^\&\*\(\)\{\}\|\;\<\>\?\'\ \	]*|*]*|"")
					arg="\"$arg\""
					;;
				esac
				args="$args $arg"
			done
			break
		fi
		;;
	-o)
		case "$1" in
		*.la) lafile="$1" ;;
		esac
		;;
	*)
		cacheupdated=
		. $logic
		case "$cacheupdated" in
		yes) @CAT@ $pre_cache $cache $post_cache > $logic ;;
		esac
		;;
	esac
	args="$args $arg"
done
cmd="$cmd $args"

@_BLNK_WRAP_SANITIZE_PATH@

@ECHO@ $cmd >> $wrapperlog
eval $cmd
wrapper_result=$?

if [ -n "$lafile" ] && [ -f "$lafile" ]; then
	. $libtool_fix_la
fi

exit ${wrapper_result}
