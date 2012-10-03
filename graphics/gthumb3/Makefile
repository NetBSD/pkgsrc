# $NetBSD: Makefile,v 1.3.2.1 2012/10/03 12:08:04 spz Exp $

DISTNAME=	gthumb-3.0.2
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gthumb/3.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://gthumb.sourceforge.net/
COMMENT=	Image viewer and browser for the GNOME Desktop
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt pkg-config gmake bison
GNU_CONFIGURE=		yes

# libopenraw (as of 0.0.9) is unusable (for quality reasons)
# gthumb will use an external "dcraw" program if available
CONFIGURE_ARGS+=	--disable-libopenraw

.include "../../devel/glib2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
