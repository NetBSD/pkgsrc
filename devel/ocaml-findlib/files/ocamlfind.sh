#!@SH@

# $NetBSD: ocamlfind.sh,v 1.4 2014/10/27 03:44:39 hiramatsu Exp $

case "$1" in
install)
	args="$@"
	install_args=
	case "$args" in
	*-destdir*) ;;
	*)
		install_args="${install_args} -destdir @DESTDIR@@OCAML_FINDLIB_PREFIX@/lib/ocaml/site-lib"
		;;
	esac
	case "$args" in
	*-ldconf*) ;;
	*)
		install_args="${install_args} -ldconf @BUILDLINK_DIR@/lib/ocaml/ld.conf"
		;;
	esac
	args="install ${install_args} ${args#install}"
	exec "@OCAML_FINDLIB_PREFIX@/bin/`basename $0`" ${args}
	;;
*)
	exec "@OCAML_FINDLIB_PREFIX@/bin/`basename $0`" "$@"
	;;
esac

