# $NetBSD: Makefile,v 1.5 2004/04/24 08:09:13 jmmv Exp $
#

DISTNAME=	gnome-pkgview-1.0.6
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.greatnorthern.demon.co.uk/packages/gnome-pkgview/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.greatnorthern.demon.co.uk/gnome-pkgview.html
COMMENT=	Displays the version of GNOME components installed

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		gnome-pkgview.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
