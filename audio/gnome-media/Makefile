# $NetBSD: Makefile,v 1.13 2002/07/17 13:22:49 rh Exp $

DISTNAME=	gnome-media-1.2.3
PKGREVISION=	2
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-media/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Set of audio/multimedia applications for GNOME

DEPENDS+=	gnome-core>=1.4.0.4nb1:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES
BUILD_USES_MSGFMT=	YES
CONFIGURE_ARGS+=--localstatedir=${X11PREFIX}/var/lib

CONFIGURE_ENV+=	XGETTEXT="${LOCALBASE}/bin/xgettext"
CPPFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
