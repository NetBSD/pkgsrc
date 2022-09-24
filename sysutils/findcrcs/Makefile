# $NetBSD: Makefile,v 1.2 2022/09/24 08:05:56 nia Exp $

DISTNAME=	findcrcs-0.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=claunia/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/claunia/findcrcs/
COMMENT=	Find and extract pieces of data by CRC, size and MD5
LICENSE=	gnu-gpl-v3 AND apache-2.0

USE_TOOLS+=		gmake
USE_LANGUAGES=		c++
TEST_TARGET=		test
INSTALLATION_DIRS=	bin share/doc/findcrcs

.include "../../mk/compiler.mk"

# Lots of nasty assumptions about things like SSE being available.
BROKEN_EXCEPT_ON_PLATFORM+=	*-*-x86_64

.if !empty(CC_VERSION:Mgcc*)
CXXFLAGS+=	-mcrc32
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/findcrcs ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/findcrcs

.include "../../mk/bsd.pkg.mk"
