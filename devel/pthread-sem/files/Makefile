# $NetBSD: Makefile,v 1.3 2008/06/12 02:14:28 joerg Exp $

LIB=		libsemaphore
LIB_VER=	1:0
LIBS?=		${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}

SRCS=		sem.c
OBJS=		${SRCS:.c=.lo}
HDRS=		semaphore.h

CFLAGS+=	-I.

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
	${BSD_INSTALL_DIR} ${DESTDIR}${LIBDIR}
	${BSD_INSTALL_DIR} ${DESTDIR}${INCLUDEDIR}
	${BSD_INSTALL_DATA} ${HDRS} ${DESTDIR}${INCLUDEDIR}
	${LIBTOOL} --mode=install ${BSD_INSTALL_LIB} ${LIB}.la ${DESTDIR}${LIBDIR}/${LIB}.la
	${BSD_INSTALL_DIR} ${DESTDIR}${MANDIR3}
	${BSD_INSTALL_DATA} sem_destroy.3 sem_getvalue.3 sem_init.3 sem_post.3 \
	    sem_wait.3 ${DESTDIR}${MANDIR3}
	${LN} -s sem_wait.3 ${DESTDIR}${MANDIR3}/sem_trywait.3

${LIB}.la: ${OBJS}
	${LIBTOOL} --mode=link ${CC} -o $@ ${CFLAGS} ${LDFLAGS} \
	    -rpath ${LIBDIR} -version-info ${LIB_VER} ${OBJS} ${LIBS}
