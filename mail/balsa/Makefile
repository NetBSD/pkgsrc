# $NetBSD: Makefile,v 1.3 2000/05/22 09:04:53 rh Exp $
#

DISTNAME=	balsa-0.8.0
CATEGORIES=	mail gnome
MASTER_SITES=	ftp://ftp.newton.cx/pub/balsa/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.balsa.net/

DEPENDS+=	pth-*:../../devel/pth
DEPENDS+=	libproplist-*:../../devel/libproplist
DEPENDS+=	gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
