# $NetBSD: Makefile,v 1.19 2012/10/31 11:16:47 asau Exp $
#

PKGVER=		0.8.4
DISTNAME=	compizconfig-backend-gconf-${PKGVER}
PKGREVISION=	14
CATEGORIES=	devel gnome
MASTER_SITES=	http://releases.compiz.org/${PKGVER}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compiz.org/
COMMENT=	Plugin (gconf) for the compiz configuration backend
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/libcompizconfig/buildlink3.mk"
.include "../../wm/compiz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
