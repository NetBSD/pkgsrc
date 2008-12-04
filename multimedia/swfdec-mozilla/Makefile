# $NetBSD: Makefile,v 1.2 2008/12/04 17:33:25 wiz Exp $
#

DISTNAME=	swfdec-mozilla-0.8.2
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec-mozilla/0.8/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://swfdec.freedesktop.org/
COMMENT=	Mozilla plugin for swfdec

GNU_CONFIGURE=	yes
USE_DIRS+=	xdg-1.4
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
#CONFIGURE_ARGS+=	--with-plugin-dir=${PREFIX}/...

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/swfdec/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
