# $NetBSD: Makefile,v 1.110 2022/07/03 12:44:09 wiz Exp $
#
# Changelog: https://hypothesis.readthedocs.io/en/latest/changes.html

DISTNAME=	hypothesis-6.48.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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

.if ${_PYTHON_VERSION} == 37 || ${_PYTHON_VERSION} == 38 || ${_PYTHON_VERSION} == 39 || ${_PYTHON_VERSION} == 310
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=1.0.0rc8:../../devel/py-exceptiongroup
.endif

.include "../../mk/bsd.pkg.mk"
