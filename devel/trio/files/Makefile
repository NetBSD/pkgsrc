# $NetBSD: Makefile,v 1.2 2006/10/31 23:13:51 joerg Exp $

LIB=		libtrio
LIB_VER=	2:0:1
LIBS?=		-lm

SRCS=		trio.c triostr.c trionan.c
HDRS=		trio.h triop.h triodef.h trionan.h triostr.h
OBJS=		${SRCS:.c=.lo}

PREFIX?=	/usr/local
LIBDIR?=	${PREFIX}/lib
INCLUDEDIR?=	${PREFIX}/include

BSD_INSTALL?=		install
BSD_INSTALL_DIR?=	${BSD_INSTALL} -d
BSD_INSTALL_DATA?=	${BSD_INSTALL} -m 444
BSD_INSTALL_LIB?=	${BSD_INSTALL} -m 644
LIBTOOL?=	libtool
LN?=		ln
RM?=		rm

.SUFFIXES: .lo
.PHONY: all clean install

.c.lo:
	${LIBTOOL} --mode=compile ${CC} -o $@ -c ${CFLAGS} ${CPPFLAGS} $<

all: ${LIB}.la

clean:
	-${LIBTOOL} --mode=clean ${RM} ${OBJS} ${LIB}.la

install:
	${BSD_INSTALL_DIR} ${DESTDIR}${LIBDIR} ${DESTDIR}${INCLUDEDIR}
	${BSD_INSTALL_DATA} ${HDRS} ${DESTDIR}${INCLUDEDIR}
	${LIBTOOL} --mode=install ${BSD_INSTALL_LIB} ${LIB}.la ${DESTDIR}${LIBDIR}/${LIB}.la

${LIB}.la: ${OBJS}
	${LIBTOOL} --mode=link ${CC} -o $@ ${CFLAGS} ${LDFLAGS} \
	    -rpath ${LIBDIR} -version-info ${LIB_VER} ${OBJS} ${LIBS}
