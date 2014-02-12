# $NetBSD: Makefile,v 1.18 2014/02/12 02:05:36 prlw1 Exp $

DISTNAME=	eog-3.10.2
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/eog/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Eye of GNOME: an image viewing and cataloging program
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config

CONFIGURE_ARGS+=	--disable-maintainer-mode

PKGCONFIG_OVERRIDE+=	data/eog.pc.in

BUILD_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

.include "../../databases/shared-mime-info/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.31.0
.include "../../devel/glib2/schemas.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.7.8
.include "../../x11/gtk3/buildlink3.mk"

# "semi-optional":
.include "../../mk/jpeg.buildlink3.mk"

# optional:
.include "../../devel/exempi/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libexif+= libexif>=0.6.14
.include "../../graphics/libexif/buildlink3.mk"
BUILDLINK_API_DEPENDS.librsvg+=	librsvg>=2.36.2
.include "../../graphics/librsvg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
