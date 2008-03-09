# $NetBSD: Makefile,v 1.1.1.1 2008/03/09 18:14:00 tnn Exp $

DISTNAME=	yabause-0.9.3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yabause/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yabause.sourceforge.net/
COMMENT=	Sega Saturn system emulator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config
USE_DIRS+=	xdg-1.4

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
