#!@SH@

# $NetBSD: ocamlfind.sh,v 1.6 2017/07/11 09:57:11 jaapb Exp $

if [ "$1" = install ]; then
	need_destdir=yes
	need_ldconf=yes
	for arg in "$@"; do
		case "$arg" in
		-destdir)
			need_destdir=no
			;;
		-ldconf)
			need_ldconf=no
			;;
		esac
	done
	if [ "$need_destdir" = "yes" ]; then
		set -- "$@" -destdir "@DESTDIR@@OCAML_FINDLIB_PREFIX@/lib/ocaml/site-lib"
	fi
	if [ "$need_ldconf" = "yes" ]; then
		set -- "$@" -ldconf "@BUILDLINK_DIR@/lib/ocaml/ld.conf"
	fi
	exec "@OCAML_FINDLIB_PREFIX@/bin/`basename $0`" "$@"
elif [ "$1" = printconf ]; then
	if [ "$2" = destdir ]; then
		ocamlfind="@OCAML_FINDLIB_PREFIX@/bin/`basename $0`"
		dir=`"$ocamlfind" printconf destdir`
		echo "@DESTDIR@$dir"
	else
		exec "@OCAML_FINDLIB_PREFIX@/bin/`basename $0`" "$@"
	fi
else
	exec "@OCAML_FINDLIB_PREFIX@/bin/`basename $0`" "$@"
fi
