# $NetBSD: Makefile,v 1.17 2000/07/06 00:46:10 hubertf Exp $
# FreeBSD Id: Makefile,v 1.6 1998/12/28 01:02:05 vanilla Exp
#

DISTNAME=	gqmpeg-0.7.2
CATEGORIES=	audio
MASTER_SITES=	http://www.netpedia.net/hosting/gqview/packages/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://www.netpedia.net/hosting/gqview/mpeg-index.html

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	mpg123-0.59r:../../audio/mpg123
DEPENDS+=	gdk-pixbuf>=0.8.0nb1:../../graphics/gdk-pixbuf
DEPENDS+=	gettext-0.10.*:../../devel/gettext

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-included-gettext=no

XCFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CFLAGS=${XCFLAGS}
MAKE_ENV+=	CFLAGS=${XCFLAGS}

.include "../../mk/bsd.pkg.mk"
