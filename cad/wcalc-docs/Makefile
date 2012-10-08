# $NetBSD: Makefile,v 1.5 2012/10/08 13:25:17 asau Exp $
#

.include "../../cad/wcalc/Makefile.common"
PKGNAME=	${DISTNAME:S/wcalc/wcalc-docs/}
PKGREVISION=	2

COMMENT=	Web Pages for the Wcalc Transmission Line Calculator

# Only enable the webpage
CONFIGURE_ARGS+=	--disable-cgi
CONFIGURE_ARGS+=	--disable-gtk1
CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--enable-htdocs
CONFIGURE_ARGS+=	--disable-libwcalc
CONFIGURE_ARGS+=	--disable-stdio
CONFIGURE_ARGS+=	--without-matlab
CONFIGURE_ARGS+=	--without-octave
CONFIGURE_ARGS+=	--without-scilab

# uses the \n sequence within replacement string feature in
# gensub() which is not currently supported in nawk
USE_TOOLS+=	gawk

.include "../../cad/libwcalc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
