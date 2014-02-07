# $NetBSD: Makefile,v 1.38 2014/02/07 13:20:16 mef Exp $

DISTNAME=	gpredict-1.3
CATEGORIES=	ham
MASTER_SITES=	http://sourceforge.net/projects/gpredict/files/Gpredict/1.3/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://groundstation.sourceforge.net/
COMMENT=	Gnome satellite tracking program
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake msgfmt pkg-config intltool
USE_PKGLOCALEDIR=yes
GNU_CONFIGURE=	yes

# needed for gpredict-0.8.0 and gtk2-2.20 -- remove on next update!
BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_PIXBUF_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
#.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../graphics/goocanvas/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
