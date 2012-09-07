# $NetBSD: Makefile,v 1.19 2012/09/07 19:16:34 adam Exp $

DISTNAME=	yabause-0.9.11.1
PKGREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yabause/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yabause.sourceforge.net/
COMMENT=	Sega Saturn system emulator
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

CONFIGURE_ENV+=	PKGMANDIR=${PKGMANDIR:Q}

.include "options.mk"

.include "../../graphics/glut/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
