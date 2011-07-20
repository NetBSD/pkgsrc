linux-ia32:
linux-intel64:

netbsd-ia32: as ld redefine-syms libicc11bsd-ia32.a
netbsd-intel64: netbsd-ia32 libicc11bsd-intel64.a

.PHONY: redefine-syms

redefine-syms:
	find icc11/lib -name *.a -exec objcopy \
	    --redefine-sym __errno_location=__errno \
	    --redefine-sym __assert_fail=__assertion_failed \
	    {} \;

libicc11bsd-ia32.a: icc11bsd-ia32.o
	ar r libicc11bsd-ia32.a icc11bsd-ia32.o
	objcopy --redefine-sym my_stderr=stderr libicc11bsd-ia32.a

icc11bsd-ia32.o: icc11bsd.c
	cc -m32 -fPIC -O icc11bsd.c -c -o icc11bsd-ia32.o

libicc11bsd-intel64.a: icc11bsd-intel64.o
	ar r libicc11bsd-intel64.a icc11bsd-intel64.o
	objcopy --redefine-sym my_stderr=stderr libicc11bsd-intel64.a

icc11bsd-intel64.o: icc11bsd.c
	cc -m64 -fPIC -O icc11bsd.c -c -o icc11bsd-intel64.o

as: as.c util.h util.c
	cc -O as.c util.c -o as

ld: ld.c util.h util.c
	cc -O ld.c util.c -o ld

install-linux-ia32:     ins-common ins-common-ia32    ins-so-ia32
install-linux-intel64:  ins-common ins-common-intel64 ins-so-intel64
install-netbsd-ia32:    ins-common ins-common-ia32    ins-bsd ins-bsd-ia32
install-netbsd-intel64: ins-common ins-common-intel64 ins-bsd ins-bsd-intel64

.PHONY: ins-common ins-common-ia32 ins-common-intel64 ins-so-ia32 ins-so-intel64 ins-bsd ins-bsd-ia32 ins-bsd-intel64

ins-common: ins-man ins-doc ins-examples ins-misc ins-inc ins-bin

.PHONY: ins-man ins-doc ins-examples ins-misc ins-inc ins-bin

ins-man:
	install -m 755 -d ${PREFIX}/${PKGMANDIR}/man1
	cd icc11/man/en_US && find man1 ! -type d | pax -rw -pp ${PREFIX}/${PKGMANDIR}

ins-doc:
	install -m 755 -d ${PREFIX}/share/doc/icc11
	install -m 644 README.bsd README.pkgsrc ${PREFIX}/share/doc/icc11
	cd icc11/Documentation && find . ! -type d | \
	    pax -rw -pp ${PREFIX}/share/doc/icc11

ins-examples:
	install -m 755 -d ${PREFIX}/share/examples/icc11
	cd icc11/Samples && find . ! -type d | \
	    pax -rw -pp ${PREFIX}/share/examples/icc11

ins-misc:
	find icc11/substitute_headers icc11/perf_headers ! -type d | \
	    pax -rw -pp ${PREFIX}

ins-inc:
	find icc11/include -maxdepth 1 ! -type d ! -name *.orig | \
	    pax -rw -pp ${PREFIX}

ins-bin:
	find icc11/bin -maxdepth 1 ! -type d | pax -rw -pp ${PREFIX}
	install -m 755 icc  ${PREFIX}/icc11/bin
	install -m 755 xiar ${PREFIX}/icc11/bin
	cp -p ${PREFIX}/icc11/bin/icc  ${PREFIX}/icc11/bin/icpc
	cp -p ${PREFIX}/icc11/bin/xiar ${PREFIX}/icc11/bin/codecov
	cp -p ${PREFIX}/icc11/bin/xiar ${PREFIX}/icc11/bin/prelink
	cp -p ${PREFIX}/icc11/bin/xiar ${PREFIX}/icc11/bin/profdcg
	cp -p ${PREFIX}/icc11/bin/xiar ${PREFIX}/icc11/bin/profmerge
	cp -p ${PREFIX}/icc11/bin/xiar ${PREFIX}/icc11/bin/proforder
	cp -p ${PREFIX}/icc11/bin/xiar ${PREFIX}/icc11/bin/tselect
	cp -p ${PREFIX}/icc11/bin/xiar ${PREFIX}/icc11/bin/xild

ins-common-ia32:    ins-inc-ia32    ins-bin-ia32    ins-lib-ia32
ins-common-intel64: ins-inc-intel64 ins-bin-intel64 ins-lib-intel64

.PHONY: ins-inc-ia32    ins-bin-ia32    ins-lib-ia32
.PHONY: ins-inc-intel64 ins-bin-intel64 ins-lib-intel64

ins-so-ia32:
	find icc11/lib/ia32 ! -type d | grep  -w so | pax -rw -pp ${PREFIX}

ins-so-intel64:
	find icc11/lib      ! -type d | grep  -w so | pax -rw -pp ${PREFIX}

ins-lib-ia32:
	find icc11/lib/ia32 ! -type d | grep -vw so | pax -rw -pp ${PREFIX}

ins-lib-intel64:
	find icc11/lib      ! -type d | grep -vw so | pax -rw -pp ${PREFIX}

ins-bin-ia32:
	find icc11/bin/ia32 ! -type d | pax -rw -pp ${PREFIX}

ins-bin-intel64:
	find icc11/bin      ! -type d | pax -rw -pp ${PREFIX}

ins-inc-ia32:
	find icc11/include/ia32 ! -type d ! -name *.orig | pax -rw -pp ${PREFIX}

ins-inc-intel64:
	find icc11/include      ! -type d ! -name *.orig | pax -rw -pp ${PREFIX}

ins-bsd-ia32: libicc11bsd-ia32.a
	install -m 644 libicc11bsd-ia32.a    ${PREFIX}/icc11/lib/ia32/libicc11bsd.a

ins-bsd-intel64: libicc11bsd-intel64.a
	install -m 644 libicc11bsd-ia32.a    ${PREFIX}/icc11/lib/ia32/libicc11bsd.a
	install -m 644 libicc11bsd-intel64.a ${PREFIX}/icc11/lib/intel64/libicc11bsd.a

ins-bsd: as ld
	install -m 755 -d ${PREFIX}/icc11/libexec
	install -m 755 as ${PREFIX}/icc11/libexec
	install -m 755 ld ${PREFIX}/icc11/libexec
