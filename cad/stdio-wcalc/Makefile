# $NetBSD: Makefile,v 1.4 2010/01/28 01:11:28 joerg Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../cad/wcalc/Makefile.common"
PKGNAME=	stdio-${DISTNAME}
PKGREVISION=	1

COMMENT=	Stdio Based Transmission Line Analysis/Synthesis Calculator

# Only enable the stdio frontend
CONFIGURE_ARGS+=	--disable-cgi
CONFIGURE_ARGS+=	--disable-gtk1
CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--disable-htdocs
CONFIGURE_ARGS+=	--disable-libwcalc
CONFIGURE_ARGS+=	--enable-stdio
CONFIGURE_ARGS+=	--without-matlab
CONFIGURE_ARGS+=	--without-octave
CONFIGURE_ARGS+=	--without-scilab

.include "../../cad/libwcalc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
