# $NetBSD: Makefile,v 1.1 2025/11/21 14:55:29 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${GNAT_NAME}-${GITHUB_TAG}.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	aunit
GITHUB_TAG=	25.2

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/aunit
COMMENT=	Ada unit test framework
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

USE_LANGUAGES=	ada

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

SUBST_CLASSES+=		version
SUBST_MESSAGE.version=	Change version in ${SUBST_FILES.version}
SUBST_STAGE.version=	post-extract
SUBST_FILES.version=	version_information
SUBST_SED.version=	-e "s,0.0,${GITHUB_TAG},"

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${GNAT_PREFIX}

TEST_TARGET=	test
TEST_DIRS=	test

TEST_MAKE_FLAGS+=	LARGS=${GPRBUILD_OPTIONS:Q}

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
