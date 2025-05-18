# $NetBSD: Makefile,v 1.98 2025/05/18 10:35:36 zafer Exp $

DISTNAME=	yabause-0.9.15
PKGREVISION=	46
CATEGORIES=	emulators
MASTER_SITES=	https://www.aydogan.net/distfiles/emulators/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yabause.org/
COMMENT=	Sega Saturn system emulator
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

CONFIGURE_ENV+=	PKGMANDIR=${PKGMANDIR:Q}

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
