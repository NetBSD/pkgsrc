#!@SH@
#
# $NetBSD: wrapper.sh,v 1.5 2021/01/12 11:19:17 jperkin Exp $

CFLAGS='@CFLAGS@'
LDFLAGS='@LDFLAGS@'
WRAPPEE='@WRAPPEE@'

for flag in ${CFLAGS}; do
	cflags="${cflags} -ccopt ${flag}"
done
for flag in ${LDFLAGS}; do
	cldflags="${cldflags} -ccopt ${flag}"
	ldflags="${ldflags} -ldopt ${flag}"
done

case "${WRAPPEE} $@" in
ocamlmklib*)
	MLFLAGS="${cflags} ${ldflags}"
	;;
*" -c "*)
	MLFLAGS="${cflags}"
	;;
*)
	MLFLAGS="${cflags} ${cldflags}"
	;;
esac

exec "@OCAML_PREFIX@/bin/${WRAPPEE}" ${MLFLAGS} "$@"
