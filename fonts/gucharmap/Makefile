# $NetBSD: Makefile,v 1.21 2004/10/03 00:14:42 tv Exp $
#

DISTNAME=	gucharmap-1.4.1
PKGREVISION=	1
CATEGORIES=	fonts gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gucharmap/1.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gucharmap.sourceforge.net/
COMMENT=	Unicode/ISO10646 character map and font viewer

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    gucharmap.pc.in

GTK2_IMMODULES=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
