#!@BUILDLINK_SHELL@
#
# $NetBSD: libtool.sh,v 1.6 2002/11/14 21:45:21 jlam Exp $

Xsed='@SED@ -e 1s/^X//'
sed_quote_subst='s/\([\\`\\"$\\\\]\)/\\\1/g'

pre_cache="@_BLNK_WRAP_PRE_CACHE@"
cache="@_BLNK_WRAP_CACHE@"
post_cache="@_BLNK_WRAP_POST_CACHE@"
logic="@_BLNK_WRAP_LOGIC@"
specificlogic="@_BLNK_WRAP_SPECIFIC_LOGIC@"
libtool_fix_la="@_BLNK_LIBTOOL_FIX_LA@"
wrapperlog="@_BLNK_WRAP_LOG@"
updatecache=${BUILDLINK_UPDATE_CACHE-yes}

cmd="@WRAPPEE@"
lafile=
doinstall=
case "$1" in
*install|*cp|*install-sh|*install.sh)
	arg="$1"; shift
	doinstall=yes
	;;
*)
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
				doinstall=yes
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
		. $specificlogic
		args="$args $arg"
	done
	;;
esac
if [ -n "$doinstall" ]; then
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
fi
cmd="$cmd $args"

@_BLNK_WRAP_ENV@
@_BLNK_WRAP_SANITIZE_PATH@

@ECHO@ $cmd >> $wrapperlog
eval $cmd
wrapper_result=$?

if [ -n "$lafile" ] && [ -f "$lafile" ]; then
	. $libtool_fix_la
fi

exit ${wrapper_result}
