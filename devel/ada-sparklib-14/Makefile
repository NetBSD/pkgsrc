# $NetBSD: Makefile,v 1.1 2025/07/28 06:52:41 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-fsf-14
PKGNAME=	sparklib-14-14.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	SPARKlib
GITHUB_TAG=	fsf-14
DISTFILES=	${DEFAULT_DISTFILES}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/SPARKlib
COMMENT=	SPARKlib libraries, FSF release 14
LICENSE=	apache-2.0

USE_LANGUAGES=	c ada

USE_TOOLS+=	gmake gsed

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

BUILD_TARGET=	generate

do-install:
	${RUN} cd ${WRKSRC} && \
	${MKDIR} ${DESTDIR}${GNAT_PREFIX}/include/spark && \
	${MKDIR} ${DESTDIR}${GNAT_PREFIX}/lib/gnat && \
	${CP} -pr src/*.ad? ${DESTDIR}${GNAT_PREFIX}/include/spark && \
	${CP} -pr *.gpr ${DESTDIR}${GNAT_PREFIX}/lib/gnat && \
	${CP} -pr proof ${DESTDIR}${GNAT_PREFIX}/lib/gnat

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

.include "../../mk/bsd.pkg.mk"
