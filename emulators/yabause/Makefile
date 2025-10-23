# $NetBSD: Makefile,v 1.101 2025/10/23 20:36:54 wiz Exp $

DISTNAME=	yabause-0.9.15
PKGREVISION=	48
CATEGORIES=	emulators
MASTER_SITES=	https://www.aydogan.net/distfiles/emulators/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yabause.org/
COMMENT=	Sega Saturn system emulator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

CONFIGURE_ENV+=	PKGMANDIR=${PKGMANDIR:Q}

.include "options.mk"

.include "../../devel/cmake/build.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
