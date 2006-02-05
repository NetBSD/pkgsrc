# $NetBSD: Makefile,v 1.5 2006/02/05 23:09:31 joerg Exp $
#

DISTNAME=		gimp-color-manager-0.1.0
PKGREVISION=		4
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
