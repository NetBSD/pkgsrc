# $NetBSD: Makefile,v 1.84 2024/01/30 18:29:17 adam Exp $
#

PKGVER=		0.8.8
DISTNAME=	compizconfig-backend-gconf-${PKGVER}
PKGREVISION=	59
CATEGORIES=	devel gnome
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compiz.org/
COMMENT=	Plugin (gconf) for the compiz configuration backend
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/startup-notification/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libcompizconfig/buildlink3.mk"
.include "../../wm/compiz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
