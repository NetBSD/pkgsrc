# $NetBSD: Makefile,v 1.2 2004/11/18 05:08:55 minskim Exp $
#

DISTNAME=	pycrack-0.01
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/py//}
CATEGORIES=	security python
MASTER_SITES=	http://www.digitalevacuation.org/pycrack/

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.digitalevacuation.org/pycrack/
COMMENT=	Python interface to cracklib

DEPENDS+=			crack>=5.0:../../security/crack

MAKE_ENV+=			MANDIR=${LOCALBASE}/man
MAKE_ENV+=			BINDIR=${LOCALBASE}/bin
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../security/libcrack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
