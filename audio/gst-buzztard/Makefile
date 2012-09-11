# $NetBSD: Makefile,v 1.8 2012/09/12 00:24:36 asau Exp $
#

DISTNAME=	gst-buzztard-0.5.0
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buzztard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://buzztard.sourceforge.net/
COMMENT=	GStreamer plugin for buzztard
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libgstbuzztard.pc.in

.include "../../audio/bml/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.liboil+=	liboil>=0.3.8
.include "../../devel/liboil/buildlink3.mk"
# actually, test dependency
BUILDLINK_DEPMETHOD.check?=	build
.include "../../devel/check/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer0.10+=	gstreamer0.10>=0.10.20
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
