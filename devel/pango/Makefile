# $NetBSD: Makefile,v 1.40 2004/04/01 18:15:16 jmmv Exp $
#

DISTNAME=		pango-1.4.0
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.4/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.4/ \
			${MASTER_SITE_GNOME:=sources/pango/1.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.pango.org/
COMMENT=		Library for layout and rendering of text

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
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	--with-qt=no

BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
