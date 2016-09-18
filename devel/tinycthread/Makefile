# $NetBSD: Makefile,v 1.1 2016/09/18 14:10:50 kamil Exp $

DISTNAME=	tinycthread-1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tinycthread/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tinycthread.github.io/
COMMENT=	Small, portable implementation of the C11 threads API
LICENSE=	zlib

USE_LIBTOOL=	yes

INSTALLATION_DIRS=	include lib
PTHREAD_AUTO_VARS=	yes

do-build:
	${RUN} cd ${WRKSRC}/source && \
		${LIBTOOL} --mode=compile --tag=CC ${CC} ${CFLAGS} \
			-c tinycthread.c
	${RUN} cd ${WRKSRC}/source && \
		${LIBTOOL} --mode=link --tag=CC ${CC} -avoid-version ${LDFLAGS} \
			-o libtinycthread.la tinycthread.lo -rpath ${PREFIX}/lib

do-install:
	${RUN} cd ${WRKSRC}/source && \
		${LIBTOOL} --mode=install ${INSTALL_LIB} \
			-c libtinycthread.la ${DESTDIR}${PREFIX}/lib/libtinycthread.la
	${INSTALL_DATA} ${WRKSRC}/source/tinycthread.h ${DESTDIR}${PREFIX}/include

do-test:
.for f in test hello
	${RUN} cd ${WRKSRC}/test && \
		${CC} -ltinycthread -L../source/.libs/ -I../source ${f}.c -o ${f} && \
		LD_LIBRARY_PATH=${WRKSRC}/source/.libs/ ./${f}
.endfor

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
