# $NetBSD: Makefile,v 1.15 2002/07/26 15:01:51 wiz Exp $

DISTNAME=	gnome-media-1.2.3
PKGREVISION=	3
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-media/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Set of audio/multimedia applications for GNOME

GNU_CONFIGURE=	YES
USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES
BUILD_USES_MSGFMT=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=--localstatedir=${X11PREFIX}/var/lib

CONFIGURE_ENV+=	XGETTEXT="${LOCALBASE}/bin/xgettext"

.include "../../www/libghttp/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
