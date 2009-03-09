# $NetBSD: Makefile,v 1.2 2009/03/09 12:18:28 hasso Exp $
#

DISTNAME=	geeqie-1.0alpha3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=geeqie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://geeqie.sourceforge.net/
COMMENT=	Image viewer

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS=		pkg-config gmake msgfmt
USE_DIRS+=		xdg-1.1

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
