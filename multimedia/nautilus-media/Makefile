# $NetBSD: Makefile,v 1.8 2004/04/01 19:08:02 jmmv Exp $
#

DISTNAME=	nautilus-media-0.8.0
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/nautilus-media/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://thomas.apestaart.org/projects/nautilus-media/
COMMENT=	Multimedia add-ons for Nautilus

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome2-dirs>=1.5:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PERL5=		build
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		gst-thumbnail.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/eel2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
