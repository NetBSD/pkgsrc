# $NetBSD: Makefile,v 1.3 2003/07/17 21:48:04 grant Exp $
#

DISTNAME=	rpy-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=rpy/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=       http://rpy.sourceforge.net/
COMMENT=	R interface for Python

USE_BUILDLINK2=	YES
PYDISTUTILSPKG=	yes

.include "../../math/py-Numeric/buildlink2.mk"
.include "../../math/R/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
