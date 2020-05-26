# $NetBSD: Makefile,v 1.5 2020/05/26 09:45:13 nia Exp $

DISTNAME=	libretro-core-info-${RETROARCH_VERSION}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_TAG=	v${RETROARCH_VERSION}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.libretro.com/
COMMENT=	Libretro core information
LICENSE=	public-domain

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${PREFIX}/share/libretro/info

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.info ${DESTDIR}${PREFIX}/share/libretro/info

.include "../../emulators/retroarch/version.mk"
.include "../../mk/bsd.pkg.mk"
