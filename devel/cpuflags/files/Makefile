# $Id: Makefile,v 1.14 2009/11/12 05:40:36 obache Exp $

VERSION=1.14

PREFIX?=/usr/local
OPSYS?=`uname`

MANDIR?=${PREFIX}/man/man1
SUBRDIR?=${PREFIX}/share/cpuflags
SHAREMKDIR?=${PREFIX}/share/mk
BINDIR?=${PREFIX}/bin
INSTALL_DATA?=install
INSTALL_MAN?=install
INSTALL_SCRIPT?=install
INSTALL_PROGRAM_DIR?=mkdir -p
INSTALL_MAN_DIR?=mkdir -p
INSTALL_DATA_DIR?=mkdir -p
SED?=sed

all:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' cpuflags.1 > cpuflags.1.out
	${SED} -e 's|@PREFIX@|${PREFIX}|g' cpuflags.mk > cpuflags.mk.out
	${SED} -e 's|@PREFIX@|${PREFIX}|g' cpuflags.sh > cpuflags.sh.out
	
clean:
	rm -rf *.out DIST

install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${BINDIR}
	${INSTALL_MAN_DIR} ${DESTDIR}${MANDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREMKDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${SUBRDIR}
	${INSTALL_SCRIPT} cpuflags.sh.out	${DESTDIR}${BINDIR}/cpuflags
	${INSTALL_MAN} cpuflags.1.out	${DESTDIR}${MANDIR}/cpuflags.1
	${INSTALL_DATA} optimize_gcc.mk	${DESTDIR}${SHAREMKDIR}/optimize_gcc.mk
	${INSTALL_DATA} cpuflags.mk.out	${DESTDIR}${SHAREMKDIR}/cpuflags.mk
	${INSTALL_DATA} subr_*		${DESTDIR}${SUBRDIR}

dist:
	mkdir -p DIST/cpuflags-${VERSION}
	cp Makefile [a-z]* DIST/cpuflags-${VERSION}
	(cd DIST;pax -w cpuflags-${VERSION}|bzip2 -9 > cpuflags-${VERSION}.tbz)
	rm -rf DIST/cpuflags-${VERSION}
