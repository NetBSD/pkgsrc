#!@SH@

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
