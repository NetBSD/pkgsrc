# $NetBSD: Makefile,v 1.14 2004/10/03 00:18:14 tv Exp $
#

DISTNAME=	apotheke-0.2
PKGREVISION=	9
CATEGORIES=	sysutils gnome
MASTER_SITES=	ftp://ftp.berlios.de/pub/apotheke/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://apotheke.berlios.de/
COMMENT=	CVS view for Nautilus

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make

GCONF2_SCHEMAS+=	apotheke.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/fam/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
