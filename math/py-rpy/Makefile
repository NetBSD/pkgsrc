# $NetBSD: Makefile,v 1.5 2003/12/04 13:50:33 adam Exp $
#

DISTNAME=	rpy-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=rpy/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=       http://rpy.sourceforge.net/
COMMENT=	R interface for Python

USE_BUILDLINK2=		YES
PYDISTUTILSPKG=		YES

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink2.mk"
.include "../../math/R/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
