# $NetBSD: Makefile,v 1.43 2024/06/09 21:10:55 wiz Exp $
#
# Release notes:
# https://lists.mercurial-scm.org/pipermail/mercurial/

DISTNAME=	hg-evolve-11.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hg-evolve/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mercurial-scm.org/doc/evolution/
COMMENT=	Experimental Mercurial extensions from Facebook
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-mercurial>=5.4nb1:../../devel/py-mercurial
TEST_DEPENDS+=	curl-[0-9]*:../../www/curl

USE_TOOLS+=	bash:test

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	rm -f ${DESTDIR}${PREFIX}/${PYSITELIB}/hgext3rd/__init__.py*
	rm -f ${DESTDIR}${PREFIX}/${PYSITELIB}/hgext3rd/__pycache__/__init__.*

# Test status as of 11.1.3
# Failed test-amend.t: output changed
# Failed test-check-compat-strings.t: output changed
# Failed test-check-sdist.t: output changed
# Failed test-evolve-content-divergent-case-A2.t: output changed
# Failed test-version-install.t: output changed
# Ran 233 tests, 6 skipped, 5 failed.

.if 0
HG_WRKSRC=	cd ../py-mercurial && ${MAKE} show-var VARNAME=WRKSRC

do-test:
	HGROOT=${HG_WRKSRC:sh}; cd ${WRKSRC}/tests && ${PYTHONBIN} $${HGROOT}/tests/run-tests.py ${_MAKE_JOBS:Q}
.endif

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
