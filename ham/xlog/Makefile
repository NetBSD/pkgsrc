# $NetBSD: Makefile,v 1.37 2010/12/25 13:39:54 mef Exp $
#

DISTNAME=	xlog-2.0.4
CATEGORIES=	ham
MASTER_SITES=	http://download.savannah.gnu.org/releases/xlog/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/xlog/
COMMENT=	Amateur Radio logging program

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=yes
USE_TOOLS+=	gmake pkg-config
DEPENDS+=	xdg-utils:../../misc/xdg-utils

CONFIGURE_ARGS+=	--enable-hamlib

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
