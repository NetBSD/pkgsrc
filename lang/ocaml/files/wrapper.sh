#!@SH@

# $NetBSD: wrapper.sh,v 1.3 2016/02/29 13:51:28 jperkin Exp $

BINDIR='@OCAML_PREFIX@'
CFLAGS='@CFLAGS@'
LDFLAGS='@LDFLAGS@'
WRAPPEE='@WRAPPEE@'

if echo "$@" | grep ' -c ' >/dev/null || [ "${WRAPPEE}" = "ocamlmklib" ]; then
	flags="${CFLAGS}"
else
	flags="${CFLAGS} ${LDFLAGS}"
fi

for f in ${flags}
do
	MLFLAGS="${MLFLAGS} -ccopt ${f}"
done

if [ "${WRAPPEE}" = "ocamlmklib" ]; then
	MLFLAGS="${MLFLAGS} ${LDFLAGS}"
fi

exec "@OCAML_PREFIX@/bin/${WRAPPEE}" ${MLFLAGS} "$@"
