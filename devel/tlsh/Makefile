# $NetBSD: Makefile,v 1.3 2024/01/14 20:07:44 schmonz Exp $

DISTNAME=		tlsh-4.8.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=trendmicro/}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/trendmicro/tlsh/
COMMENT=		Fuzzy matching library
LICENSE=		apache-2.0

USE_CMAKE=		yes
CONFIGURE_DIRS=		build/release
CMAKE_ARG_PATH=		../..
CMAKE_ARGS+=		-DTLSH_SHARED_LIBRARY=1
USE_LANGUAGES=		c c++
TEST_TARGET=		test

INSTALLATION_DIRS=	bin include lib

post-extract:
	${MKDIR} ${WRKSRC}/${CONFIGURE_DIRS}

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
