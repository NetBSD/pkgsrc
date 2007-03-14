# $NetBSD: Makefile,v 1.19 2007/03/14 11:55:41 markd Exp $
#

DISTNAME=	rpy-0.99.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rpy.sourceforge.net/
COMMENT=	R interface for Python

PYDISTUTILSPKG=		YES
PYTHON_VERSIONS_ACCEPTED=	24 23

BUILDLINK_API_DEPENDS.R+= R>=2.4.1

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
