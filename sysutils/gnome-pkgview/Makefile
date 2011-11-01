# $NetBSD: Makefile,v 1.36 2011/11/01 06:02:33 sbd Exp $
#

DISTNAME=	gnome-pkgview-1.0.6
PKGREVISION=	22
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.greatnorthern.demon.co.uk/packages/gnome-pkgview/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.greatnorthern.demon.co.uk/gnome-pkgview.html
COMMENT=	Displays the version of GNOME components installed

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		intltool msgfmt pkg-config
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

GCONF_SCHEMAS=		gnome-pkgview.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
