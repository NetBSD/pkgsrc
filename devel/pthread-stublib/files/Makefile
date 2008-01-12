# $NetBSD: Makefile,v 1.2 2008/01/12 12:35:39 joerg Exp $

all: libpthstub.la

libpthstub.la: pthread-stubs.lo
	${LIBTOOL} --mode=link ${CC} -o $@ $? -rpath ${PREFIX}/lib

pthread-stubs.lo: pthread-stubs.c
	${LIBTOOL} --mode=compile ${CC} -c -o $@ $?

install:
	${LIBTOOL} --mode=install ${BSD_INSTALL_LIB} libpthstub.la \
		${DESTDIR}${PREFIX}/lib
