# $NetBSD: Makefile,v 1.38 2004/04/14 16:15:23 jmmv Exp $

DISTNAME=		ee-0.3.12
PKGREVISION=		10
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ee/0.3/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Image viewer based on imlib by the Rasterman.  Gtk clone of xv

USE_BUILDLINK2=		# defined
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	# defined
USE_X11BASE=		# defined
USE_GNU_TOOLS+=		make

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

LOCALSTATEDIR=		/var/gnome

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${BUILDLINK_PREFIX.glib}

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
