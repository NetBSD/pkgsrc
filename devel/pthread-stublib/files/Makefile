# $NetBSD: Makefile,v 1.1.1.1 2006/03/21 19:23:08 drochner Exp $

all: libpthstub.la

libpthstub.la: pthread-stubs.lo
	${LIBTOOL} --mode=link ${CC} -o $@ $? -rpath ${PREFIX}/lib

pthread-stubs.lo: pthread-stubs.c
	${LIBTOOL} --mode=compile ${CC} -c -o $@ $?

install:
	${LIBTOOL} --mode=install ${BSD_INSTALL_LIB} libpthstub.la \
		${PREFIX}/lib
