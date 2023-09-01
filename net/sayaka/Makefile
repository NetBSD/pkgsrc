# $NetBSD: Makefile,v 1.45 2023/09/01 10:07:00 nia Exp $

DISTNAME=	sayaka-3.6.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=isaki68k/}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION_NOREV}//}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/isaki68k/sayaka
COMMENT=	Terminal specific Twitter client
LICENSE=	modified-bsd AND mit

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config
BUILD_TARGET=		sayaka

USE_CXX_FEATURES+=	c++17

INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sayaka ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif
.include "../../security/mbedtls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
