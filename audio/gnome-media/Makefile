# $NetBSD: Makefile,v 1.2 1999/08/30 23:11:15 tron Exp $
#

DISTNAME=	gnome-media-1.0.9.1
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=gnome-1.0/sources/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	esound-0.2.8:../../audio/esound
DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	gnome-core-1.0.9:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES

CONFIGURE_ENV+=	XGETTEXT="${LOCALBASE}/bin/xgettext"
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
