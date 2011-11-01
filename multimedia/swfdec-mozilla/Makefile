# $NetBSD: Makefile,v 1.13 2011/11/01 06:02:15 sbd Exp $
#

DISTNAME=	swfdec-mozilla-0.8.2
PKGREVISION=	10
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
