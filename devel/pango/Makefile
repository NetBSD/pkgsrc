# $NetBSD: Makefile,v 1.45 2004/08/31 11:53:07 jmmv Exp $
#

DISTNAME=		pango-1.4.1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.4/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.4/ \
			${MASTER_SITE_GNOME:=sources/pango/1.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.pango.org/
COMMENT=		Library for layout and rendering of text

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	pango.pc.in
PKGCONFIG_OVERRIDE+=	pangoft2.pc.in
PKGCONFIG_OVERRIDE+=	pangox.pc.in
PKGCONFIG_OVERRIDE+=	pangowin32.pc.in
PKGCONFIG_OVERRIDE+=	pangoxft.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/libdata
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--with-qt=no

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8

# XXX: Set up compatibility links for pango-1.4.0; this is just a workaround
# for our broken libtool naming, and it should be removed when our libtool
# is fixed.
post-install:
.for f in pango pangoft2 pangox pangoxft
	cd ${PREFIX}/lib && ${LN} -fs lib${f}-1.0.so.400 lib${f}-1.0.so.399
	cd ${PREFIX}/lib && ${LN} -fs lib${f}-1.0.so.400.1 lib${f}-1.0.so.399.1
.endfor
.undef f

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
