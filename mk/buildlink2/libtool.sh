#!@BUILDLINK_SHELL@
#
# $NetBSD: libtool.sh,v 1.7 2002/12/22 19:02:44 jlam Exp $

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
cacheall=${BUILDLINK_CACHE_ALL-no}

cmd="@WRAPPEE@"
lafile=
doinstall=
case "$1" in
*install|*cp|*install-sh|*install.sh)
	arg="$1"; shift
	doinstall=yes
	;;
*)
	while @TEST@ $# -gt 0; do
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
			if @TEST@ "$arg" = "--mode=install" || \
			   @TEST@ "$arg" = "--mode" -a "$1" = "install"; then
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
		cmd="$cmd $arg"
	done
	;;
esac
if @TEST@ -n "$doinstall"; then
	cmd="$cmd $arg"
	while @TEST@ $# -gt 0; do
		arg="$1"; shift
		case $arg in
		*[\`\"\$\\]*)
			arg=`@ECHO@ "X$arg" | $Xsed -e "$sed_quote_subst"`
			;;
		esac
		case $arg in
		*[\[\~\#\^\&\*\(\)\{\}\|\;\<\>\?\'\ \	]*|*]*|"")
			arg="\"$arg\""
			;;
		esac
		cmd="$cmd $arg"
	done
fi

@_BLNK_WRAP_ENV@
@_BLNK_WRAP_SANITIZE_PATH@

@ECHO@ $cmd >> $wrapperlog
eval $cmd
wrapper_result=$?

if @TEST@ -n "$lafile" && @TEST@ -f "$lafile"; then
	. $libtool_fix_la
fi

exit ${wrapper_result}
