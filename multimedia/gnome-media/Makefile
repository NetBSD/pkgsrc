# $NetBSD: Makefile,v 1.1.1.1 2004/02/22 16:30:59 jmmv Exp $

DISTNAME=		gnome-media-1.2.3
PKGREVISION=		9
CATEGORIES=		multimedia gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-media/1.2/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of audio/multimedia applications for GNOME

DEPENDS+=		gnome1-dirs>=1.2:../../misc/gnome1-dirs

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ENV+=	XGETTEXT="${LOCALBASE}/bin/xgettext"

.include "../../www/libghttp/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
