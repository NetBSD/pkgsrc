# $NetBSD: Makefile,v 1.1.1.1 1999/03/31 21:00:21 garbled Exp $
#

DISTNAME=	ee-0.3.8
CATEGORIES=	x11 gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/gnome-1.0/sources/ee/ \
		ftp://ftp.circ.us.eu.org/mirrors/ftp.gnome.org/sources/ee/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/gnome-1.0/sources/ee/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/gnome-1.0/sources/ee/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-core-1.0.3:../../x11/gnome-core

NOT_FOR_ARCHS=	alpha	# problems with gtk

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

LOCALSTATEDIR=	/var/gnome

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${LOCALBASE}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

.include "../../mk/bsd.pkg.mk"
