# $NetBSD: Makefile,v 1.10 2001/08/13 18:38:55 rh Exp $

DISTNAME=	gnome-media-1.2.3
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-media/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Set of audio/multimedia applications for GNOME

DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES

CONFIGURE_ENV+=	XGETTEXT="${LOCALBASE}/bin/xgettext"
CPPFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
