# $NetBSD: Makefile,v 1.1.1.1 2004/02/07 00:29:37 jmmv Exp $
#

DISTNAME=	nautilus-media-0.3.3.1
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/nautilus-media/0.3/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://thomas.apestaart.org/projects/nautilus-media/
COMMENT=	Multimedia add-ons for Nautilus

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PERL5=		build
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		gst-thumbnail.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/eel2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../multimedia/gstreamer/buildlink2.mk"
.include "../../multimedia/gst-plugins/buildlink2.mk"
.include "../../sysutils/nautilus/buildlink2.mk"
.include "../../textproc/intltool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
