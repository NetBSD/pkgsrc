# $NetBSD: Makefile,v 1.3 2004/02/14 17:21:36 jlam Exp $
#

DISTNAME=		blib-1.0.2
PKGREVISION=		1
CATEGORIES=		devel graphics
MASTER_SITES=		http://sven.gimp.org/blinkenlights/old/

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.blinkenlights.de/
COMMENT=		Blinkenlights library

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

SHLIBTOOL_OVERRIDE=	modules/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/blib-directfb.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/blib-gtk.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/blib.pc.in

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	--enable-gtk-doc=no

# XXX: fix this for GNU/Linux, provide appropriate PLIST.
CONFIGURE_ARGS+=	--disable-directfb

post-extract:
	${TOUCH} ${WRKSRC}/modules/libtool

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
