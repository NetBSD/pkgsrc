# $NetBSD: Makefile,v 1.40 2018/11/14 22:21:47 kleink Exp $

DISTNAME=	ucview-0.22
PKGREVISION=	36
CATEGORIES=	graphics
MASTER_SITES=	http://unicap-imaging.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://unicap-imaging.org/
COMMENT=	Video capture and display program based on unicap

USE_TOOLS+=		perl pkg-config gmake intltool
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/GConf/schemas.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/unicap/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
