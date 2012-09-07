# $NetBSD: Makefile,v 1.46 2012/09/07 19:16:55 adam Exp $
#

DISTNAME=	xlog-2.0.4
PKGREVISION=	7
CATEGORIES=	ham
MASTER_SITES=	http://download.savannah.gnu.org/releases/xlog/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/xlog/
COMMENT=	Amateur Radio logging program

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--enable-hamlib

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
