# $NetBSD: Makefile,v 1.17 2002/09/23 18:08:36 wiz Exp $

DISTNAME=	gnome-media-1.2.3
PKGREVISION=	3
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-media/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Set of audio/multimedia applications for GNOME

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES
BUILD_USES_MSGFMT=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=--localstatedir=${X11PREFIX}/var/lib

CONFIGURE_ENV+=	XGETTEXT="${LOCALBASE}/bin/xgettext"

.include "../../www/libghttp/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
