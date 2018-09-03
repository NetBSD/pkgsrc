# $NetBSD: Makefile,v 1.60 2018/09/03 07:39:34 adam Exp $

DISTNAME=	hypothesis-3.70.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hypothesis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/HypothesisWorks/hypothesis
COMMENT=	Python library for property based testing
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-attrs>=16.0.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-coverage>=4.0:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
