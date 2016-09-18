# $NetBSD: Makefile,v 1.1 2016/09/18 16:47:55 kamil Exp $

DISTNAME=	linenoise-1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=antirez/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/antirez/linenoise/
COMMENT=	Small self-contained alternative to readline and libedit
LICENSE=	2-clause-bsd

USE_LIBTOOL=	yes

INSTALLATION_DIRS=	include lib

do-build:
	${RUN} cd ${WRKSRC} && \
		${LIBTOOL} --mode=compile --tag=CC ${CC} ${CFLAGS} \
			-c linenoise.c
	${RUN} cd ${WRKSRC} && \
		${LIBTOOL} --mode=link --tag=CC ${CC} -avoid-version ${LDFLAGS} \
			-o liblinenoise.la linenoise.lo -rpath ${PREFIX}/lib

do-install:
	${RUN} cd ${WRKSRC} && \
		${LIBTOOL} --mode=install ${INSTALL_LIB} \
			-c liblinenoise.la ${DESTDIR}${PREFIX}/lib/liblinenoise.la
	${INSTALL_DATA} ${WRKSRC}/linenoise.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
