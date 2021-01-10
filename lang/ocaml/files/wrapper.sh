#!@SH@
#
# $NetBSD: wrapper.sh,v 1.4 2021/01/10 11:13:33 jperkin Exp $

CFLAGS='@CFLAGS@'
LDFLAGS='@LDFLAGS@'
WRAPPEE='@WRAPPEE@'

for flag in ${CFLAGS}; do
	cflags="${cflags} -ccopt ${flag}"
done
for flag in ${LDFLAGS}; do
	ldflags="${ldflags} -ccopt ${flag}"
done

if echo "$@" | grep ' -c ' >/dev/null; then
	MLFLAGS="${cflags}"
else
	MLFLAGS="${cflags} ${ldflags}"
fi

exec "@OCAML_PREFIX@/bin/${WRAPPEE}" ${MLFLAGS} "$@"
