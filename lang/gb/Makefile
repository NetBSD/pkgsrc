# $NetBSD: Makefile,v 1.7 2001/08/11 18:41:59 rh Exp $
#

DISTNAME=	gb-0.0.20
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/gb/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/gb/
COMMENT=	Basic for Gnome

DEPENDS+=	gnome-core>1.4.0:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CPPFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
