# $NetBSD: Makefile,v 1.14 2002/02/01 17:02:18 mjl Exp $
#

DISTNAME=	balsa-1.2.4
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.theochem.kth.se/~pawsa/balsa/ \
		ftp://ftp.newton.cx/pub/balsa/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.balsa.net/
COMMENT=	GNOME EMail client

DEPENDS+=	glib>=1.2.1:../../devel/glib
DEPENDS+=	imlib>=1.9.2:../../graphics/imlib
DEPENDS+=	gnome-libs>=1.2.1:../../x11/gnome-libs
DEPENDS+=	gnome-print>=0.25:../../print/gnome-print
DEPENDS+=	libpspell>=0.8.3:../../textproc/libpspell
DEPENDS+=	pcre-[0-9]*:../../devel/pcre
DEPENDS+=	gtkhtml-[0-9]*:../../www/gtkhtml
DEPENDS+=	libiconv-*:../../converters/libiconv

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--disable-more-warnings --without-esmtp \
			--enable-pcre --disable-threads 
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
USE_BUILDLINK_ONLY=	yes

# USE_PTHREAD=	native pth

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/libtool/buildlink.mk"
.include "../../devel/libproplist/buildlink.mk"
.include "../../devel/pcre/buildlink.mk"
.include "../../textproc/libpspell/buildlink.mk"
.include "../../x11/gnome-core/buildlink.mk"
# .include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
