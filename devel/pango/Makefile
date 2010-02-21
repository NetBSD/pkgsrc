# $NetBSD: Makefile,v 1.140 2010/02/21 23:51:25 tron Exp $

DISTNAME=		pango-1.26.2
PKGREVISION=		1
CATEGORIES=		devel fonts
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/pango/1.26/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.pango.org/
COMMENT=		Library for layout and rendering of text
LICENSE=		gnu-lgpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
TEST_TARGET=		check
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE=	pango-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pango.pc.in
PKGCONFIG_OVERRIDE+=	pangocairo-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pangocairo.pc.in
PKGCONFIG_OVERRIDE+=	pangoft2-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pangoft2.pc.in
PKGCONFIG_OVERRIDE+=	pangowin32-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pangowin32.pc.in
PKGCONFIG_OVERRIDE+=	pangox-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pangox.pc.in
PKGCONFIG_OVERRIDE+=	pangoxft-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pangoxft.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/libdata

CHECK_FILES_SKIP+=	${PREFIX}/libdata/pango/pango.modules

PLIST_VARS+=		carbon

.include "options.mk"

# Workaround for Upstream Bug#562310.
# for more detail, see also PR#41475.
TOOLS_NOOP+=	gtkdoc-rebase

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.17.3
.include "../../devel/glib2/buildlink3.mk"
# XXX: later maybe add an option for libthai to provide pango-thai-lang.la?
#.include "../../devel/libthai/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.8.0
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.5.0
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.7nb3
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
