# $NetBSD: Makefile,v 1.37 2013/11/25 12:00:48 wiz Exp $
#

DISTNAME=	swfdec-mozilla-0.8.2
PKGREVISION=	33
CATEGORIES=	multimedia
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec-mozilla/0.8/

MAINTAINER=	martin@NetBSD.org
HOMEPAGE=	http://swfdec.freedesktop.org/
COMMENT=	Mozilla plugin for swfdec
LICENSE=	gnu-lgpl-v2.1 # or later

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CFLAGS+=		-g
CONFIGURE_ARGS+=	--with-plugin-dir=${PREFIX}/lib/netscape/plugins

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/swfdec/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
