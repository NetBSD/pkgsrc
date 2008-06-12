# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:22 joerg Exp $
#

DISTNAME=	compizconfig-backend-gconf-0.6.0
CATEGORIES=	devel gnome
MASTER_SITES=	http://releases.compiz-fusion.org/0.6.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.compiz-fusion.org/
COMMENT=	Plugin (gconf) for the compiz configuration backend

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/libcompizconfig/buildlink3.mk"
.include "../../wm/compiz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
