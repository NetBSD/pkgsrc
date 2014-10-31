#!@SH@

# $NetBSD: ocamlfind.sh,v 1.5 2014/10/31 01:00:30 hiramatsu Exp $

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
fi
exec "@OCAML_FINDLIB_PREFIX@/bin/`basename $0`" "$@"
