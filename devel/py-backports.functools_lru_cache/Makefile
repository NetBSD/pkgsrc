# $NetBSD: Makefile,v 1.13 2023/04/30 15:38:26 wiz Exp $

DISTNAME=	backports.functools_lru_cache-1.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.functools_lru_cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/backports.functools_lru_cache/
COMMENT=	Backport of functools.lru_cache from Python 3.3
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-backports-[0-9]*:../../devel/py-backports
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm5
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py27-test-cov
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

PYTHON_VERSIONS_ACCEPTED=	27

# XXX: also needs py-test-black
#do-test:
#	cd ${WRKSRC}/tests && pytest-${PYVERSSUFFIX}

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/backports/__init__.*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
