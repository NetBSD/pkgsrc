# $NetBSD: Makefile,v 1.148 2024/12/16 05:53:02 adam Exp $
#
# Changelog: https://hypothesis.readthedocs.io/en/latest/changes.html

DISTNAME=	hypothesis-6.122.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hypothesis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/HypothesisWorks/hypothesis
COMMENT=	Python library for property based testing
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-attrs>=22.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.1.0:../../devel/py-sortedcontainers

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=1.0.0:../../devel/py-exceptiongroup
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} hypothesis hypothesis-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
