# $NetBSD: Makefile,v 1.26 2002/10/19 10:54:52 rh Exp $

DISTNAME=		ee-0.3.12
PKGREVISION=		2
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ee/0.3/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Image viewer based on imlib by the Rasterman.  Gtk clone of xv

USE_BUILDLINK2=		# defined
USE_X11BASE=		# defined
USE_GMAKE=		# defined

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

LOCALSTATEDIR=		/var/gnome

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--with-glib-prefix=${BUILDLINK_PREFIX.glib}
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
