# $NetBSD: Makefile,v 1.1.1.1 2004/04/01 19:09:47 jmmv Exp $
#

DISTNAME=	gnome-netstatus-2.6.0
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-netstatus/2.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Network status applet for the GNOME panel

DEPENDS+=		gnome2-dirs>=1.5:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		netstatus.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
