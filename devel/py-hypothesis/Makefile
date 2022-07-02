# $NetBSD: Makefile,v 1.109 2022/07/02 09:10:39 adam Exp $
#
# Changelog: https://hypothesis.readthedocs.io/en/latest/changes.html

DISTNAME=	hypothesis-6.48.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hypothesis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/HypothesisWorks/hypothesis
COMMENT=	Python library for property based testing
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-attrs>=19.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.1.0:../../devel/py-sortedcontainers

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
