# $NetBSD: Makefile,v 1.13 2006/02/05 23:10:50 joerg Exp $
#

DISTNAME=	gnome-pkgview-1.0.6
PKGREVISION=	4
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.greatnorthern.demon.co.uk/packages/gnome-pkgview/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.greatnorthern.demon.co.uk/gnome-pkgview.html
COMMENT=	Displays the version of GNOME components installed

BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		gnome-pkgview.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
