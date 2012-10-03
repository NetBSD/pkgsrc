# $NetBSD: Makefile,v 1.35.2.1 2012/10/03 12:08:00 spz Exp $
#

DISTNAME=		gimp-color-manager-0.1.0
PKGREVISION=		29
CATEGORIES=		graphics
MASTER_SITES=		ftp://www.virtual-sub.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.khk.net/color/color_manager.html
COMMENT=		Gimp Color Manager plugin

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool pkg-config
GNU_CONFIGURE=		yes

PTHREAD_AUTO_VARS=	yes

MAKE_ENV+=		mkinstalldirs=${INSTALL_DATA_DIR:Q}

.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
