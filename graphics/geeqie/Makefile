# $NetBSD: Makefile,v 1.8 2010/02/20 20:50:34 gdt Exp $
#

DISTNAME=	geeqie-1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=geeqie/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://geeqie.sourceforge.net/
COMMENT=	Image viewer
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS=		bash:run gmake intltool msgfmt pkg-config
REPLACE_BASH=		plugins/rotate/geeqie-rotate
REPLACE_BASH+=		plugins/ufraw/geeqie-ufraw
REPLACE_BASH+=		plugins/import/geeqie-import

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
