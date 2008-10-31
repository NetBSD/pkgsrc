# $NetBSD: Makefile,v 1.29 2008/10/31 12:52:01 wiz Exp $
#

DISTNAME=	xlog-1.5
PKGREVISION=	3
CATEGORIES=	ham
MASTER_SITES=	http://www.qsl.net/pg4i/download/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.qsl.net/pg4i/linux/xlog.html
COMMENT=	Amateur Radio logging program

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS=	xdg-1.3
GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--enable-hamlib

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
