# $NetBSD: Makefile,v 1.14 2020/10/06 17:52:16 wiz Exp $

DISTNAME=	hg-evolve-10.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hg-evolve/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://www.mercurial-scm.org/doc/evolution/
COMMENT=	Experimental Mercurial extensions from Facebook
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mercurial>=5.4nb1:../../devel/py-mercurial
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=0:../../databases/py-sqlite3
TEST_DEPENDS+=	curl-[0-9]*:../../www/curl

USE_TOOLS+=	bash:test

post-install:
	rm -f ${DESTDIR}${PREFIX}/${PYSITELIB}/hgext3rd/__init__.py*
	rm -f ${DESTDIR}${PREFIX}/${PYSITELIB}/hgext3rd/__pycache__/__init__.*

# Test status
# as of 10.0.2 with mercurial 5.5.2
# Ran 187 tests, 4 skipped, 7 failed.
# test-evolve-phase-divergence.t
# test-check-compat-strings.t
# test-evolve.t
# test-evolve-public-content-divergent-corner-cases.t
# test-evolve-public-content-divergent-discard.t
# test-evolve-public-content-divergent-main.t
# test-unstability-resolution-result.t

.if 0
HG_WRKSRC=	cd ../py-mercurial && ${MAKE} show-var VARNAME=WRKSRC

do-test:
	HGROOT=${HG_WRKSRC:sh}; cd ${WRKSRC}/tests && ${PYTHONBIN} $${HGROOT}/tests/run-tests.py ${_MAKE_JOBS:Q}
.endif

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
