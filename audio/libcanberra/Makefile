# $NetBSD: Makefile,v 1.1.1.1 2008/10/16 15:17:47 drochner Exp $
#

DISTNAME=	libcanberra-0.10
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/libcanberra/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/libcanberra/
COMMENT=	Desktop event sound library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_DIRS+=	gnome2-1.5
GCONF_SCHEMAS+=	libcanberra.schemas

PKGCONFIG_OVERRIDE+=	libcanberra-gtk.pc.in
PKGCONFIG_OVERRIDE+=	libcanberra.pc.in

.include "../../devel/libltdl/convenience.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
