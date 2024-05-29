# $NetBSD: Makefile,v 1.36 2024/05/29 16:32:58 adam Exp $
#

DISTNAME=	lasem-0.4.1
PKGREVISION=	33
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/lasem/0.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://live.gnome.org/Lasem
COMMENT=	Lasem is a library for rendering SVG and Mathml
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex gettext gmake intltool pkg-config
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	lasem.pc.in

.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.6.0
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.0.0nb2
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
