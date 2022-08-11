# $NetBSD: Makefile,v 1.37 2022/08/11 06:41:58 wiz Exp $

DISTNAME=	sayaka-3.5.3
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=isaki68k/}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION_NOREV}//}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/isaki68k/sayaka
COMMENT=	Terminal specific Twitter client
LICENSE=	modified-bsd AND mit

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c99 c++17
USE_TOOLS+=		pkg-config
BUILD_TARGET=		sayaka

INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sayaka ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif
.include "../../graphics/png/buildlink3.mk"
.include "../../security/mbedtls/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
