# $NetBSD: Makefile,v 1.1.1.1 2000/10/17 17:18:27 rh Exp $
#

DISTNAME=	gb-0.0.12
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/gb/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/gb/

DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
