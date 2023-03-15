# $NetBSD: Makefile,v 1.13 2023/03/15 13:04:49 adam Exp $

DISTNAME=	Bottleneck-1.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=B/Bottleneck/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kwgoodman/bottleneck
COMMENT=	Collection of fast NumPy array functions written in C
LICENSE=	2-clause-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 # numpy

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
