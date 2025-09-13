# $NetBSD: Makefile,v 1.3 2025/09/13 05:51:05 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-fsf-14
PKGNAME=	sparklib14-14.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	SPARKlib
GITHUB_TAG=	fsf-14
DISTFILES=	${DEFAULT_DISTFILES}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/SPARKlib
COMMENT=	SPARKlib libraries, FSF release 14
LICENSE=	apache-2.0

SUPERSEDES+=	sparklib-14-14.*

USE_LANGUAGES=	c ada

USE_TOOLS+=	gmake gsed

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

BUILD_TARGET=	generate

INSTALLATION_DIRS+=	${GNAT_PREFIX}/include/spark
INSTALLATION_DIRS+=	${GNAT_PREFIX}/lib/gnat

do-install:
	${RUN} cd ${WRKSRC} && \
	${INSTALL_LIB} src/*.ad? ${DESTDIR}${GNAT_PREFIX}/include/spark && \
	${INSTALL_LIB} *.gpr ${DESTDIR}${GNAT_PREFIX}/lib/gnat && \
	${FIND} -f proof \( -type d \) -exec ${INSTALL_LIB_DIR} "${DESTDIR}${GNAT_PREFIX}/lib/gnat/{}" ";" && \
	${FIND} -f proof \( -type f -or -type l \) -exec ${INSTALL_LIB} "{}" "${DESTDIR}${GNAT_PREFIX}/lib/gnat/{}" ";"

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

.include "../../mk/bsd.pkg.mk"
