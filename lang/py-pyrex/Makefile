# $NetBSD: Makefile,v 1.8 2004/08/19 20:44:31 recht Exp $

DISTNAME=	Pyrex-0.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/P/p/}
CATEGORIES=	lang python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/~greg/python/Pyrex/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.cosc.canterbury.ac.nz/~greg/python/Pyrex/
COMMENT=	A Language for Writing Python Extension Modules

PYTHON_VERSIONS_ACCEPTED=	23 23pth 22 22pth

PYDISTUTILSPKG=	yes
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
