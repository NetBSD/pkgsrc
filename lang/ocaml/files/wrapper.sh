#!@SH@

# $NetBSD: wrapper.sh,v 1.2 2005/02/04 21:35:51 adrianp Exp $

BINDIR='@OCAML_PREFIX@'
CFLAGS='@CFLAGS@'
LDFLAGS='@LDFLAGS@'

if echo "$@" | grep ' -c ' >/dev/null
then
	flags="${CFLAGS}"
else
	flags="${CFLAGS} ${LDFLAGS}"
fi

for f in ${flags}
do
	MLFLAGS="${MLFLAGS} -ccopt ${f}"
done

exec "@OCAML_PREFIX@/bin/`basename $0`" ${MLFLAGS} "$@"
