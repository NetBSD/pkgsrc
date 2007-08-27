# $Id: Makefile,v 1.12 2007/08/27 10:08:29 abs Exp $

VERSION=1.14

PREFIX?=/usr/local
OPSYS?=`uname`

MANDIR?=${PREFIX}/man/man1
SUBRDIR?=${PREFIX}/share/cpuflags
SHAREMKDIR?=${PREFIX}/share/mk
BINDIR?=${PREFIX}/bin
BSD_INSTALL_DATA?=install
BSD_INSTALL_MAN?=install
BSD_INSTALL_SCRIPT?=install
SED?=sed

all:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' cpuflags.1 > cpuflags.1.out
	${SED} -e 's|@PREFIX@|${PREFIX}|g' cpuflags.mk > cpuflags.mk.out
	${SED} -e 's|@PREFIX@|${PREFIX}|g' cpuflags.sh > cpuflags.sh.out
	
clean:
	rm -rf *.out DIST

install:
	mkdir -p ${BINDIR} ${MANDIR} ${SHAREMKDIR} ${SUBRDIR}
	${BSD_INSTALL_SCRIPT} cpuflags.sh.out	${BINDIR}/cpuflags
	${BSD_INSTALL_MAN} cpuflags.1.out	${MANDIR}/cpuflags.1
	${BSD_INSTALL_DATA} optimize_gcc.mk	${SHAREMKDIR}/optimize_gcc.mk
	${BSD_INSTALL_DATA} cpuflags.mk.out	${SHAREMKDIR}/cpuflags.mk
	${BSD_INSTALL_DATA} subr_*		${SUBRDIR}

dist:
	mkdir -p DIST/cpuflags-${VERSION}
	cp Makefile [a-z]* DIST/cpuflags-${VERSION}
	(cd DIST;pax -w cpuflags-${VERSION}|bzip2 -9 > cpuflags-${VERSION}.tbz)
	rm -rf DIST/cpuflags-${VERSION}
