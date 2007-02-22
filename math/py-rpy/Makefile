# $NetBSD: Makefile,v 1.18 2007/02/22 19:26:47 wiz Exp $
#

DISTNAME=	rpy-0.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rpy.sourceforge.net/
COMMENT=	R interface for Python

PYDISTUTILSPKG=		YES
PYTHON_VERSIONS_ACCEPTED=	24 23

BUILDLINK_API_DEPENDS.R+= R>=2.3.1

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
