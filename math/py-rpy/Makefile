# $NetBSD: Makefile,v 1.8 2004/11/21 05:31:03 markd Exp $
#

DISTNAME=	rpy-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=rpy/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=       http://rpy.sourceforge.net/
COMMENT=	R interface for Python

USE_BUILDLINK3=		YES
PYDISTUTILSPKG=		YES

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
