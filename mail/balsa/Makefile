# $NetBSD: Makefile,v 1.12 2001/09/27 23:18:20 jlam Exp $
#

DISTNAME=	balsa-1.0.0
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.theochem.kth.se/~pawsa/balsa/ \
		ftp://ftp.newton.cx/pub/balsa/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.balsa.net/
COMMENT=	GNOME EMail client

DEPENDS+=	libpspell-[0-9]*:../../textproc/libpspell
DEPENDS+=	pth-[0-9]*:../../devel/pth
DEPENDS+=	libproplist-[0-9]*:../../devel/libproplist
DEPENDS+=	gnome-core-[0-9]*:../../x11/gnome-core

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
CONFIGURE_ARGS+=--disable-more-warnings
CPPFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
