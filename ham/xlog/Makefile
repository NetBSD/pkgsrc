# $NetBSD: Makefile,v 1.61 2014/05/05 00:48:02 ryoon Exp $
#

DISTNAME=	xlog-2.0.5
PKGREVISION=	10
CATEGORIES=	ham
MASTER_SITES=	http://download.savannah.gnu.org/releases/xlog/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/xlog/
COMMENT=	Amateur Radio logging program

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

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
