# $NetBSD: Makefile,v 1.8 2000/10/22 09:33:23 rh Exp $
#

DISTNAME=	balsa-1.0.pre3
PKGNAME=	${DISTNAME:S/pre/p/}
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.theochem.kth.se/~pawsa/balsa/ \
		ftp://ftp.newton.cx/pub/balsa/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.balsa.net/

DEPENDS+=	libpspell-*:../../textproc/libpspell
DEPENDS+=	pth-*:../../devel/pth
DEPENDS+=	libproplist-*:../../devel/libproplist
DEPENDS+=	gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
CONFIGURE_ARGS+=--disable-more-warnings
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
