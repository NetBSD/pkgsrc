# $NetBSD: Makefile,v 1.9 2023/01/24 18:36:24 wiz Exp $

DISTNAME=	re2-${GITHUB_TAG:S/-//g}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	2020-08-01

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/re2
COMMENT=	Regular expression library
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++11
TEST_ENV=	LD_LIBRARY_PATH=${WRKSRC}
TEST_TARGET=	test

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

PKGCONFIG_OVERRIDE=	re2.pc
INSTALLATION_DIRS+=	lib/pkgconfig

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixup pathnames
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	re2.pc
SUBST_SED.path=		-e 's,@includedir@,${PREFIX}/include,'
SUBST_SED.path+=	-e 's,@libdir@,${PREFIX}/lib,'

post-install:
	${INSTALL_DATA} ${WRKSRC}/re2.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
