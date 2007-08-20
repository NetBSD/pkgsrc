# $Id: Makefile,v 1.8 2007/08/20 11:21:20 abs Exp $

VERSION=1.10

PREFIX?=/usr/local
OPSYS?=`uname`

MANDIR?=${PREFIX}/man/man1
SUBRDIR?=${PREFIX}/share/cpuflags
SHAREMKDIR?=${PREFIX}/share/mk
BINDIR?=${PREFIX}/bin
INSTALL?=install
SED?=sed

all:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' cpuflags.1 > cpuflags.1.out
	${SED} -e 's|@PREFIX@|${PREFIX}|g' cpuflags.mk > cpuflags.mk.out
	${SED} -e 's|@PREFIX@|${PREFIX}|g' cpuflags.sh > cpuflags.sh.out
	
clean:
	rm -rf *.out DIST

install:
	mkdir -p ${BINDIR} ${MANDIR} ${SHAREMKDIR} ${SUBRDIR}
	${INSTALL} cpuflags.sh.out	${BINDIR}/cpuflags
	${INSTALL} cpuflags.1.out	${MANDIR}/cpuflags.1
	${INSTALL} optimize_gcc.mk	${SHAREMKDIR}/optimize_gcc.mk
	${INSTALL} cpuflags.mk.out	${SHAREMKDIR}/cpuflags.mk
	${INSTALL} subr_*		${SUBRDIR}

dist:
	mkdir -p DIST/cpuflags-${VERSION}
	cp Makefile [a-z]* DIST/cpuflags-${VERSION}
	(cd DIST;pax -w cpuflags-${VERSION}|bzip2 -9 > cpuflags-${VERSION}.tbz)
	rm -rf DIST/cpuflags-${VERSION}
