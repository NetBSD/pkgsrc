# $NetBSD: Makefile,v 1.6 2001/06/11 06:34:39 jlam Exp $
#

DISTNAME=	gb-0.0.18
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
