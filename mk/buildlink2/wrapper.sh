#!/bin/sh
Xsed='@SED@ -e 1s/^X//'
sed_quote_subst='s/\([\\`\\"$\\\\]\)/\\\1/g'
sed_whitespace_subst='s/\([ 	]\)/\\\1/g'
precache="@_BLNK_WRAP_PRE_CACHE@"
cache="@_BLNK_WRAP_CACHE@"
postcache="@_BLNK_WRAP_POST_CACHE@"
logic="@_BLNK_WRAP_LOGIC@"
wrapperlog="@BUILDLINK_DIR@/.wrapper.log"
for arg
do
	cacheupdated=
	case "$arg" in
	-[IL]*@BUILDLINK_DIR@*|-[IL]*@BUILDLINK_X11_DIR@*|-[IL]*@_BLNK_X11PKG_DIR@*)
		args="$args $arg"
		;;
	-[IL]*|-[Dl]*|@LOCALBASE@/*/lib*|@X11BASE@/*/lib*)
		. $logic
		case "$cacheupdated" in
		yes) @CAT@ $precache $cache $postcache > $logic ;;
		esac
		;;
	# Double-quote args containing other shell metacharacters.
	*[\[\~\#\^\&\*\(\)\{\}\|\;\<\>\?\'\ \	]*|*]*|"")
		args="$args \"$arg\""
		;;
	*)
		args="$args $arg"
		;;
	esac
done
@_BLNK_WRAP_SANITIZE_PATH@
eval @ECHO@ @WRAPPEE@ "$args" >> $wrapperlog
eval exec @WRAPPEE@ "$args"
