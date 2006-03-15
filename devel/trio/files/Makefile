# $NetBSD: Makefile,v 1.1 2006/03/15 16:44:50 joerg Exp $

LIB=		libtrio
LIB_VER=	1:0
LIBS?=		-lm

SRCS=		trio.c strio.c
HDRS=		trio.h triop.h
OBJS=		${SRCS:.c=.lo}

PREFIX?=	/usr/local
LIBDIR?=	${PREFIX}/lib
INCLUDEDIR?=	${PREFIX}/include
MANDIR?=	${PREFIX}/${PKGMANDIR}
MANDIR3?=	${MANDIR}/man3

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
	${BSD_INSTALL_DIR} ${LIBDIR} ${INCLUDEDIR}
	${BSD_INSTALL_DATA} ${HDRS} ${INCLUDEDIR}
	${LIBTOOL} --mode=install ${BSD_INSTALL_LIB} ${LIB}.la ${LIBDIR}/${LIB}.la
	${BSD_INSTALL_DIR} ${MANDIR3}
	${BSD_INSTALL_DATA} man/man3/strio.3 man/man3/trio_printf.3 \
	    man/man3/trio_register.3 man/man3/trio_scanf.3 ${MANDIR3}

${LIB}.la: ${OBJS}
	${LIBTOOL} --mode=link ${CC} -o $@ ${CFLAGS} ${LDFLAGS} \
	    -rpath ${LIBDIR} -version-info ${LIB_VER} ${OBJS} ${LIBS}
