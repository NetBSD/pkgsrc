# $NetBSD: Makefile,v 1.53 2011/11/27 13:31:23 cheusov Exp $

DISTNAME=		bzr-${VER}
CATEGORIES=		devel scm
MASTER_SITES=		http://launchpad.net/bzr/${VER:R}/${VER}/+download/
VER=			2.4.2

MAINTAINER=		ddeus.pkgsrc@mailnull.com
HOMEPAGE=		http://bazaar-vcs.org/
COMMENT=		Bazaar open source distributed version control system
LICENSE=		gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-expat>=0:../../textproc/py-expat
BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils
BUILD_DEPENDS+=		${PYPKGPREFIX}-pyrex>=0:../../lang/py-pyrex

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
# Only this python versions are supported, see:
# http://doc.bazaar.canonical.com/bzr.dev/en/whats-new/whats-new-in-2.4.html
PYTHON_VERSIONS_ACCEPTED=	27 26

PYTHON_PATCH_SCRIPTS=		bzr bzrlib/weave.py
PYTHON_PATCH_SCRIPTS+=		bzrlib/patiencediff.py bzrlib/_patiencediff_py.py
PYTHON_PATCH_SCRIPTS+=		bzrlib/plugins/bash_completion/bashcomp.py
PYTHON_PATCH_SCRIPTS+=		bzrlib/tests/ssl_certs/create_ssls.py

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
DEPENDS+=		${PYPKGPREFIX}-medusa>=0:../../net/py-medusa
.endif

SUBST_CLASSES+=			python
SUBST_MESSAGE.python=		Fix python path for test case.
SUBST_STAGE.python=		post-extract
SUBST_FILES.python+=		Makefile
SUBST_SED.python+=		-e 's,=python,=${PYTHONBIN},'

post-build:
	cd ${WRKSRC} && ${PYTHONBIN} tools/generate_docs.py man

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ./bzr selftest -v

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
