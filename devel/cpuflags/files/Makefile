# $Id: Makefile,v 1.2 2005/05/01 22:03:37 abs Exp $

VERSION=0.87

PREFIX?=/usr/local
OPSYS?=`uname`

MANDIR?=${PREFIX}/man/man1
MKDIR?=${PREFIX}/share/mk
BINDIR?=${PREFIX}/bin

all:
	sed -e 's|@PREFIX@|${PREFIX}|g' cpuflags.1 > cpuflags.1.out
	sed -e 's|@PREFIX@|${PREFIX}|g' cpuflags.mk > cpuflags.mk.out
	
clean:
	rm -rf *.out out

install:
	mkdir -p ${BINDIR} ${MANDIR} ${MKDIR}
	install cpuflags.${OPSYS} ${BINDIR}/cpuflags
	install cpuflags.1.out 	  ${MANDIR}/cpuflags.1
	install optimize_gcc.mk   ${MKDIR}/optimize_gcc.mk
	install cpuflags.mk.out   ${MKDIR}/cpuflags.mk

dist:
	mkdir -p out/cpuflags-${VERSION}
	cp Makefile *.* out/cpuflags-${VERSION}
	(cd out;pax -w cpuflags-${VERSION} | bzip2 -9 > cpuflags-${VERSION}.tbz)
	rm -rf out/cpuflags-${VERSION}


