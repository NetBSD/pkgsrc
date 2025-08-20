# $NetBSD: Makefile,v 1.5 2025/08/20 11:34:53 wiz Exp $

DISTNAME=		tlsh-4.8.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=trendmicro/}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/trendmicro/tlsh/
COMMENT=		Fuzzy matching library
LICENSE=		apache-2.0

CMAKE_CONFIGURE_ARGS+=	-DTLSH_SHARED_LIBRARY=1
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5
USE_LANGUAGES=		c c++
TEST_TARGET=		test

INSTALLATION_DIRS=	include

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${DESTDIR}${PREFIX}/include

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
