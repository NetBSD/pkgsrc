# $NetBSD: Makefile,v 1.6 2000/06/01 11:23:13 rh Exp $

DISTNAME=	gnome-media-1.0.51
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-media/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_PKGLIBTOOL=	YES
USE_X11BASE=	YES

CONFIGURE_ENV+=	XGETTEXT="${LOCALBASE}/bin/xgettext"
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
