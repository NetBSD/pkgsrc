# $NetBSD: Makefile,v 1.16 2003/12/28 23:37:06 jmmv Exp $
#

DISTNAME=	librsvg-2.5.0
PKGNAME=	${DISTNAME:S/-/2-/}
PKGREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/librsvg/2.5/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://librsvg.sourceforge.net/
COMMENT=	SVG library for GNOME2

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/librsvg-2.0.pc.in

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-gimp=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html/librsvg2

.if !defined(PKG_SYSCONFDIR.gtk2) || empty(PKG_SYSCONFDIR.gtk2)
MESSAGE_SUBST+=		PKG_SYSCONFDIR.gtk2="${PKG_SYSCONFBASE}/gtk-2.0"
.else
MESSAGE_SUBST+=		PKG_SYSCONFDIR.gtk2="${PKG_SYSCONFDIR.gtk2}"
.endif

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libgsf/buildlink2.mk"
.include "../../devel/pango/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
