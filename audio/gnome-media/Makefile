# $NetBSD: Makefile,v 1.4 1999/11/07 21:58:11 tron Exp $

DISTNAME=	gnome-media-1.0.51
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=gnome-1.0/sources/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES

CONFIGURE_ENV+=	XGETTEXT="${LOCALBASE}/bin/xgettext"
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
