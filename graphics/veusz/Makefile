# $NetBSD: Makefile,v 1.8 2006/07/04 16:15:01 drochner Exp $
#

DISTNAME=		veusz-0.10
CATEGORIES=		graphics
MASTER_SITES=		http://download.gna.org/veusz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.gna.org/veusz/
COMMENT=		Scientific plotting package

PYDISTUTILSPKG=		yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../x11/py-qt3-modules/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
