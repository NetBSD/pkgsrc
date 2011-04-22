# $NetBSD: Makefile,v 1.10 2011/04/22 13:44:18 obache Exp $
#

DISTNAME=	swfdec-mozilla-0.8.2
PKGREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec-mozilla/0.8/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://swfdec.freedesktop.org/
COMMENT=	Mozilla plugin for swfdec

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
#CONFIGURE_ARGS+=	--with-plugin-dir=${PREFIX}/...

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/swfdec/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
