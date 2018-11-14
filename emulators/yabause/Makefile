# $NetBSD: Makefile,v 1.47 2018/11/14 22:21:27 kleink Exp $

DISTNAME=	yabause-0.9.14
PKGREVISION=	9
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yabause/}

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
