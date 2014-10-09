#!@SH@

# $NetBSD: ocamlfind.sh,v 1.3 2014/10/09 20:53:15 jaapb Exp $

case "$@" in
*install*)
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
	args="${args%%install*}install ${install_args}${args##*install}"
	exec "@OCAML_FINDLIB_PREFIX@/bin/`basename $0`" ${args}
	;;
*)
	exec "@OCAML_FINDLIB_PREFIX@/bin/`basename $0`" "$@"
	;;
esac

