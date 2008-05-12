# $NetBSD: Makefile,v 1.1.1.1 2008/05/12 12:06:59 jmcneill Exp $
#

DISTNAME=	compizconfig-backend-gconf-0.6.0
CATEGORIES=	devel gnome
MASTER_SITES=	http://releases.compiz-fusion.org/0.6.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.compiz-fusion.org/
COMMENT=	Plugin (gconf) for the compiz configuration backend

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/libcompizconfig/buildlink3.mk"
.include "../../wm/compiz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
