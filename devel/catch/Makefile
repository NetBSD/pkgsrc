# $NetBSD: Makefile,v 1.7 2022/08/19 00:01:00 tnn Exp $

DISTNAME=	Catch-1.12.2
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=catchorg/}
GITHUB_PROJECT=	Catch2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/catchorg/Catch2/
COMMENT=	C++-native, framework for unit-tests, TDD and BDD
LICENSE=	boost-license

TEST_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
NO_BUILD=	yes
AUTO_MKDIRS=	yes

do-install:
	${RUN} ${INSTALL_DATA} ${WRKSRC}/single_include/catch.hpp \
		${DESTDIR}${PREFIX}/include

do-test:
	${MKDIR} ${WRKSRC}/projects/Generated
	${RUN} cd ${WRKSRC}/projects/Generated &&	\
	  ${PREFIX}/bin/cmake ../.. &&			\
	  ${GMAKE} &&					\
	  ./SelfTest

.include "../../mk/bsd.pkg.mk"
