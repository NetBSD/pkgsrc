# $NetBSD: Makefile,v 1.32 2004/01/22 13:39:23 jmmv Exp $
#

DISTNAME=		pango-1.2.5
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.2/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.2/ \
			${MASTER_SITE_GNOME:=sources/pango/1.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.pango.org/
COMMENT=		Library for layout and rendering of text

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/pango.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangoft2.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangox.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangowin32.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangoxft.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/libdata
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	--with-qt=no

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
