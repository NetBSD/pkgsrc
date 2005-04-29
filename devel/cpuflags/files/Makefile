# $Id: Makefile,v 1.1 2005/04/29 12:56:05 abs Exp $

PREFIX?=/usr/local
OPSYS?=`uname`

MANDIR?=${PREFIX}/man/man1
MKDIR?=${PREFIX}/share/mk
BINDIR?=${PREFIX}/bin

all:
	sed -e 's|@PREFIX@|${PREFIX}|g' cpuflags.1 > cpuflags.1.out
	sed -e 's|@PREFIX@|${PREFIX}|g' cpuflags.mk > cpuflags.mk.out
	
clean:
	rm -f *.out

install:
	mkdir -p ${BINDIR} ${MANDIR} ${MKDIR}
	install cpuflags.${OPSYS} ${BINDIR}/cpuflags
	install cpuflags.1.out 	  ${MANDIR}/cpuflags.1
	install optimize_gcc.mk   ${MKDIR}/optimize_gcc.mk
	install cpuflags.mk.out   ${MKDIR}/cpuflags.mk
