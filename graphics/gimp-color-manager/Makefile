# $NetBSD: Makefile,v 1.3 2005/12/31 12:32:36 wiz Exp $
#

DISTNAME=		gimp-color-manager-0.1.0
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		ftp://www.virtual-sub.org/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.khk.net/color/color_manager.html
COMMENT=		Gimp Color Manager plugin

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

MAKE_ENV+=		mkinstalldirs=${INSTALL_DATA_DIR:Q}

.include "../../graphics/gimp/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
