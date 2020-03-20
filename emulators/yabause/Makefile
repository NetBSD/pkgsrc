# $NetBSD: Makefile,v 1.54 2020/03/20 11:57:37 nia Exp $

DISTNAME=	yabause-0.9.15
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	https://download.tuxfamily.org/yabause/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yabause.sourceforge.net/
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
