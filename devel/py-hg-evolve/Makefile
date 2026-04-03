# $NetBSD: Makefile,v 1.52 2026/04/03 17:34:18 wiz Exp $
#
# Release notes:
# https://lists.mercurial-scm.org/pipermail/mercurial/

DISTNAME=	hg_evolve-12.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hg-evolve/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.mercurial-scm.org/EvolveExtension
COMMENT=	Experimental Mercurial extensions from Facebook
LICENSE=	gnu-gpl-v2

PATCH_SITES=		https://foss.heptapod.net/mercurial/evolve/-/commit/
PATCHFILES=		8ec80fb4b0ce4247b61051014a4fb891bf327a89.diff \
			0144bd9214df0457a966177eb7217e2b2991965a.diff \
			1c1cd671da5c3c547184b0b13dbb59b8c848d09c.diff
PATCH_DIST_STRIP=	-p1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-mercurial>=5.4nb1:../../devel/py-mercurial
TEST_DEPENDS+=	curl-[0-9]*:../../www/curl

USE_TOOLS+=	bash:test

post-install:
	rm -f ${DESTDIR}${PREFIX}/${PYSITELIB}/hgext3rd/__init__.py*
	rm -f ${DESTDIR}${PREFIX}/${PYSITELIB}/hgext3rd/__pycache__/__init__.*

# Test status as of 11.1.9
# Failed test-check-compat-strings.t: expects hg copy is a repository
# Failed test-check-sdist.t: missing files in upstream list
# Failed test-version-install.t: Unexpected PIP compatibility warning

.if 0
HG_WRKSRC=	cd ../py-mercurial && ${MAKE} show-var VARNAME=WRKSRC

do-test:
	HGROOT=${HG_WRKSRC:sh}; cd ${WRKSRC}/tests && ${PYTHONBIN} $${HGROOT}/tests/run-tests.py ${_MAKE_JOBS:Q}
.endif

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
