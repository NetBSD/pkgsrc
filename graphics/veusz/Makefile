# $NetBSD: Makefile,v 1.5 2006/02/10 11:13:52 drochner Exp $
#

DISTNAME=		veusz-0.9
CATEGORIES=		graphics
MASTER_SITES=		http://download.gna.org/veusz/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://home.gna.org/veusz/
COMMENT=		Scientific plotting package

PYDISTUTILSPKG=		yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../x11/py-qt3-modules/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
