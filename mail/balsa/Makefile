# $NetBSD: Makefile,v 1.2 2000/04/25 07:07:28 rh Exp $
#

DISTNAME=	balsa-0.8.0-pre1
PKGNAME=	balsa-0.8.0p1
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
