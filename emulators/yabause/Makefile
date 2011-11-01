# $NetBSD: Makefile,v 1.13 2011/11/01 06:01:11 sbd Exp $

DISTNAME=	yabause-0.9.10
PKGREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yabause/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yabause.sourceforge.net/
COMMENT=	Sega Saturn system emulator
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config

.include "../../devel/SDL/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtkglext+=	gtkglext>=1.2.0nb4
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
