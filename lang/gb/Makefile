# $NetBSD: Makefile,v 1.4 2001/02/17 09:07:08 agc Exp $
#

DISTNAME=	gb-0.0.17
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/gb/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/gb/
COMMENT=	Basic for Gnome

DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
