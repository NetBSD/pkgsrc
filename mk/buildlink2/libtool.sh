#!/bin/sh
Xsed='@SED@ -e 1s/^X//'
sed_quote_subst='s/\([\\`\\"$\\\\]\)/\\\1/g'
sed_whitespace_subst='s/\([ 	]\)/\\\1/g'
precache="@_BLNK_WRAP_PRE_CACHE@"
cache="@_BLNK_WRAP_CACHE@"
postcache="@_BLNK_WRAP_POST_CACHE@"
logic="@_BLNK_WRAP_LOGIC@"
wrapperlog="@BUILDLINK_DIR@/.wrapper.log"

# fix_la:
#	In the "relink_command" line, we make the following replacements:
#
#	       "libfoo.la" -> "-L./.libs libfoo.la"
#		"dirpath/libfoo.la" -> "-Ldirpath/.libs libfoo.la"
#
#	This allows the libraries to be found within ${WRKSRC} during
#	relinking.  We rely on the proper rpath settings to be set by
#	libtool.
#
fix_la()
{
	lafile=$1
	labase=`@BASENAME@ $lafile .la`
	ladir=`@DIRNAME@ $lafile`
	laifile=${ladir}/.libs/${labase}.lai
	. ${ladir}/${labase}.la
	relink=
	for i in ${relink_command}; do
		case "$i" in
		-I*|-D*)
			;;
		-L*)
			case "$relink" in
			*"$i "*) ;;
			*"$i") ;;
			*) relink="${relink} $i" ;;
			esac
			;;
		$lafile)
			relink="${relink} $i"
			;;
		*.la)
			ltlibsdir=`@DIRNAME@ $i`/.libs
			case "$relink" in
			*"-L$ltlibsdir "*) ;;
			*"-L$ltlibsdir") ;;
			*) relink="$relink -L$ltlibsdir" ;;
			esac
			relink="${relink} $i"
			;;
		*)
			relink="${relink} $i"
			;;
		esac
	done
	if [ -n "$relink" ]; then
		@MV@ -f $lafile ${lafile}.blsav
		(
			@CAT@ ${lafile}.blsav | @SED@ -e '/^relink_command=/,$d'
			@ECHO@ "relink_command='$relink'"
			@CAT@ ${lafile}.blsav | @SED@ -e '1,/^relink_command=/d'
		) > $lafile
		@ECHO@ "==> Fixed $lafile" >> $wrapperlog
	fi
	if [ -n "$laifile" ] && [ -f "$laifile" ]; then
		fix_lai $laifile
	fi
}

# fix_lai:
#	Remove redundant -Ldir and -llib options in the "dependency_libs"
#	line of the to-be-installed libtool archives.
#
fix_lai()
{
	@SED@	@_BLNK_WRAP_LT_UNTRANSFORM_SED@ \
		$laifile > ${laifile}.tmp
	. ${laifile}.tmp
	L=; l=; lexist=; prev=
	for i in ${dependency_libs}; do
		case "$i" in
		$prev)
			;;
		-L*)
			case "$L" in
			*"$i "*) ;;
			*"$i") ;;
			*) L="$L $i" ;;
			esac
			;;
		-l*)
			lexist=1
			l="$l $i"
			;;
		*)
			l="$l $i"
			;;
		esac
		prev="$i"
	done
	if [ -z "$lexist" ]; then
		L=
	fi
	deps="$L$l"
	@MV@ -f $laifile ${laifile}.blsav
	(
		@CAT@ ${laifile}.tmp | @SED@ -e '/^dependency_libs=/,$d'
		@ECHO@ "dependency_libs='$deps'"
		@CAT@ ${laifile}.tmp | @SED@ -e '1,/^dependency_libs=/d'
	) > ${laifile}
	@RM@ -f ${laifile}.tmp
	@ECHO@ "==> Fixed $laifile" >> $wrapperlog
}

lafile=
while [ $# -gt 0 ]
do
	arg="$1"; shift
	cacheupdated=
	case "$arg" in
	--fix-la)
		case "$1" in
		*.la) fix_la $1; exit ;;
		esac
		;;
	-o)
		case "$1" in
		*.la) lafile="$1" ;;
		esac
		args="$args $arg"
		;;
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
eval @WRAPPEE@ "$args"
wrapper_result=$?

if [ -n "$lafile" ] && [ -f "$lafile" ]; then
	fix_la $lafile
fi

return ${wrapper_result}
