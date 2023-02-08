# $NetBSD: Makefile,v 1.117 2023/02/08 10:31:14 adam Exp $
#
# Changelog: https://hypothesis.readthedocs.io/en/latest/changes.html

DISTNAME=	hypothesis-6.67.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hypothesis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/HypothesisWorks/hypothesis
COMMENT=	Python library for property based testing
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-attrs>=19.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.1.0:../../devel/py-sortedcontainers

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} != 311
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=1.0.0:../../devel/py-exceptiongroup
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} hypothesis hypothesis-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
