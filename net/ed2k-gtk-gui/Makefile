# $NetBSD: Makefile,v 1.35.2.1 2012/10/03 12:09:03 spz Exp $

DISTNAME=		ed2k-gtk-gui-0.6.3
PKGREVISION=		17
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ed2k-gtk-gui/}

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://ed2k-gtk-gui.sourceforge.net/
COMMENT=		GUI for the eDonkey2000 and Overnet

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CONFIGURE_LDFLAGS=${LDFLAGS:M*:Q}
LDFLAGS.DragonFly+=	-lX11 -lgmodule-2.0

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
