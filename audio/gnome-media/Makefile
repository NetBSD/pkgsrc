# $NetBSD: Makefile,v 1.7 2000/06/01 17:17:58 rh Exp $

DISTNAME=	gnome-media-1.2.0
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-media/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES

CONFIGURE_ENV+=	XGETTEXT="${LOCALBASE}/bin/xgettext"
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
