# $NetBSD: Makefile,v 1.28 2022/01/09 11:58:14 wiz Exp $
#
# Release notes:
# https://www.mercurial-scm.org/pipermail/evolve-testers/

DISTNAME=	hg-evolve-10.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/post//}
PKGREVISION=	2
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

# Test status as of 10.1.0 with mercurial 5.6:
# Failed test-check-compat-strings.t: output changed
# Failed test-check-debian.t: output changed
# Failed test-evolve-content-divergent-case-A2.t: output changed
# Ran 194 tests, 4 skipped, 3 failed.

.if 0
HG_WRKSRC=	cd ../py-mercurial && ${MAKE} show-var VARNAME=WRKSRC

do-test:
	HGROOT=${HG_WRKSRC:sh}; cd ${WRKSRC}/tests && ${PYTHONBIN} $${HGROOT}/tests/run-tests.py ${_MAKE_JOBS:Q}
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
