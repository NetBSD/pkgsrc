# $NetBSD: Makefile,v 1.12 2000/01/02 18:02:41 tron Exp $

DISTNAME=		ee-0.3.11
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/releases/gnome-1.0.53/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.gnome.org/

DEPENDS=		gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes

LOCALSTATEDIR=		/var/gnome

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

.include "../../mk/bsd.pkg.mk"
