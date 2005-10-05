# $NetBSD: Makefile,v 1.61 2005/10/05 14:01:48 wiz Exp $
#

DISTNAME=		pango-1.10.1
CATEGORIES=		devel fonts
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.8/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.8/ \
			${MASTER_SITE_GNOME:=sources/pango/1.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.pango.org/
COMMENT=		Library for layout and rendering of text

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGINSTALL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
TEST_TARGET=		check
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	pango-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pango.pc.in
PKGCONFIG_OVERRIDE+=	pangocairo.pc-uninstalled.in
PKGCONFIG_OVERRIDE+=	pangocairo.pc.in
PKGCONFIG_OVERRIDE+=	pangoft2.pc-uninstalled.in
PKGCONFIG_OVERRIDE+=	pangoft2.pc.in
PKGCONFIG_OVERRIDE+=	pangowin32.pc-uninstalled.in
PKGCONFIG_OVERRIDE+=	pangowin32.pc.in
PKGCONFIG_OVERRIDE+=	pangox.pc-uninstalled.in
PKGCONFIG_OVERRIDE+=	pangox.pc.in
PKGCONFIG_OVERRIDE+=	pangoxft.pc-uninstalled.in
PKGCONFIG_OVERRIDE+=	pangoxft.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/libdata
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--with-qt=no

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8
BUILDLINK_DEPENDS.cairo+=	cairo>=1.0.0
BUILDLINK_DEPENDS.glib2+=	glib2>=2.6.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
