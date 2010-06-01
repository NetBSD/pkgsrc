# $NetBSD: Makefile,v 1.49 2010/06/01 13:31:40 tnn Exp $

DISTNAME=		bzr-${VER}
CATEGORIES=		devel scm
MASTER_SITES=		http://launchpad.net/bzr/2.0/${VER}/+download/
VER=			2.0.3

MAINTAINER=		epg@NetBSD.org
HOMEPAGE=		http://bazaar-vcs.org/
COMMENT=		Bazaar open source distributed version control system
LICENSE=		gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-expat>=0:../../textproc/py-expat
BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_PATCH_SCRIPTS=		bzr bzrlib/weave.py

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
