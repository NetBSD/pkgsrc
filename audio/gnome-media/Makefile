# $NetBSD: Makefile,v 1.22 2003/01/27 19:47:49 jmmv Exp $

DISTNAME=		gnome-media-1.2.3
PKGREVISION=		4
CATEGORIES=		audio gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-media/1.2/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of audio/multimedia applications for GNOME

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--localstatedir=${SCROLLKEEPER_DATADIR}

CONFIGURE_ENV+=	XGETTEXT="${LOCALBASE}/bin/xgettext"

.include "../../www/libghttp/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
