#!@BUILDLINK_SHELL@
#
# $NetBSD: libtool.sh,v 1.1.2.2 2003/08/28 19:12:56 jlam Exp $

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

cmd="@WRAPPEE@"
lafile=
case "$1" in
*install|*cp|*install-sh|*install.sh)
	arg="$1"; shift
	. $libtool_do_install
	;;
*)
	while $test $# -gt 0; do
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
			if $test "$arg" = "--mode=install" || \
			   $test "$arg" = "--mode" -a "$1" = "install"; then
				. $libtool_do_install
				break
			fi
			;;
		-o)
			case "$1" in
			*.la) lafile="$1" ;;
			esac
			;;
		*)
			cachehit=no
			skipcache=no
			. $marshall
			. $private_cache
			case $skipcache,$cachehit in
			no,no)	. $cache ;;
			esac
			case $cachehit in
			no)	. $logic ;;
			esac
			;;
		esac
		cmd="$cmd $arg"
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
