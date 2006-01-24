# $NetBSD: Makefile,v 1.10 2006/01/24 07:32:01 wiz Exp $
#

DISTNAME=		blib-1.0.2
PKGREVISION=		3
CATEGORIES=		devel graphics
MASTER_SITES=		http://sven.gimp.org/blinkenlights/old/

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.blinkenlights.de/
COMMENT=		Blinkenlights library

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

SHLIBTOOL_OVERRIDE=	modules/libtool
PKGCONFIG_OVERRIDE+=	blib-directfb.pc.in
PKGCONFIG_OVERRIDE+=	blib-gtk.pc.in
PKGCONFIG_OVERRIDE+=	blib.pc.in

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	--enable-gtk-doc=no

# XXX: fix this for GNU/Linux, provide appropriate PLIST.
CONFIGURE_ARGS+=	--disable-directfb

post-extract:
	${TOUCH} ${WRKSRC}/modules/libtool

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
