# $NetBSD: Makefile,v 1.6 1999/07/14 23:12:06 tron Exp $
#

DISTNAME=		ee-0.3.8
CATEGORIES=		x11 gnome
MASTER_SITES=		ftp://ftp.gnome.org/pub/GNOME/gnome-1.0/sources/ee/ \
			ftp://ftp.circ.us.eu.org/mirrors/ftp.gnome.org/sources/ee/ \
			ftp://ftp.sunet.se/pub/X11/GNOME/gnome-1.0/sources/ee/ \
			ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/gnome-1.0/sources/ee/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.gnome.org/

DEPENDS=		gnome-core-1.0.7:../../x11/gnome-core

NOT_FOR_PLATFORM=	*-*-alpha	# problems with gtk

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes

LOCALSTATEDIR=		/var/gnome

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

.include "../../mk/bsd.pkg.mk"
