# $NetBSD: Makefile,v 1.5 2006/02/05 23:10:46 joerg Exp $
#

DISTNAME=	pycrack-0.01
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/py//}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	http://www.digitalevacuation.org/pycrack/

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.digitalevacuation.org/pycrack/
COMMENT=	Python interface to cracklib

DEPENDS+=			crack>=5.0:../../security/crack

MAKE_ENV+=			MANDIR=${LOCALBASE}/man
MAKE_ENV+=			BINDIR=${LOCALBASE}/bin
USE_TOOLS+=		gmake

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../security/libcrack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
