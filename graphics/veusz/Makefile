# $NetBSD: Makefile,v 1.13 2010/02/10 19:17:40 joerg Exp $
#

DISTNAME=		veusz-0.10
PKGREVISION=		4
CATEGORIES=		graphics
MASTER_SITES=		http://download.gna.org/veusz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.gna.org/veusz/
COMMENT=		Scientific plotting package

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../x11/py-qt3-modules/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
