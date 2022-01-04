# $NetBSD: Makefile,v 1.4 2022/01/04 20:54:33 wiz Exp $

DISTNAME=	python-subunit-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-subunit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/subunit
COMMENT=	Python implementation of subunit test streaming protocol
LICENSE=	apache-2.0 OR modified-bsd

DEPENDS+=	${PYPKGPREFIX}-extras-[0-9]*:../../devel/py-extras
DEPENDS+=	${PYPKGPREFIX}-testtools>=0.9.34:../../devel/py-testtools
TEST_DEPENDS+=	${PYPKGPREFIX}-fixtures-[0-9]*:../../devel/py-fixtures
TEST_DEPENDS+=	${PYPKGPREFIX}-testscenarios-[0-9]*:../../devel/py-testscenarios

PYTHON_VERSIONED_DEPENDENCIES=	hypothesis:test

USE_LANGUAGES=	# none

post-install:
.for f in subunit-1to2 subunit-1to2 subunit-2to1 subunit-filter subunit-ls \
	subunit-notify subunit-output subunit-stats subunit-tags subunit2csv \
	subunit2disk subunit2gtk subunit2junitxml subunit2pyunit tap2subunit
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${f} ${f}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC}/python && ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
