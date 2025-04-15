# $NetBSD: Makefile,v 1.16 2025/04/15 13:03:38 adam Exp $

DISTNAME=	biopython-1.85
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	http://biopython.org/DIST/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://biopython.org/
COMMENT=	Python libraries for computational molecular biology
LICENSE=	biopython

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
