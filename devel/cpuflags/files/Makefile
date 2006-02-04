# $Id: Makefile,v 1.6 2006/02/04 15:08:33 abs Exp $

VERSION=0.97

PREFIX?=/usr/local
OPSYS?=`uname`

MANDIR?=${PREFIX}/man/man1
MKDIR?=${PREFIX}/share/mk
BINDIR?=${PREFIX}/bin
INSTALL?=install
SED?=sed

all:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' cpuflags.1 > cpuflags.1.out
	${SED} -e 's|@PREFIX@|${PREFIX}|g' cpuflags.mk > cpuflags.mk.out
	
clean:
	rm -rf *.out out

install:
	mkdir -p ${BINDIR} ${MANDIR}	${MKDIR}
	${INSTALL} cpuflags.${OPSYS}	${BINDIR}/cpuflags
	${INSTALL} cpuflags.1.out	${MANDIR}/cpuflags.1
	${INSTALL} optimize_gcc.mk	${MKDIR}/optimize_gcc.mk
	${INSTALL} cpuflags.mk.out	${MKDIR}/cpuflags.mk

dist:
	mkdir -p out/cpuflags-${VERSION}
	cp Makefile *.* out/cpuflags-${VERSION}
	(cd out;pax -w cpuflags-${VERSION} | bzip2 -9 > cpuflags-${VERSION}.tbz)
	rm -rf out/cpuflags-${VERSION}
