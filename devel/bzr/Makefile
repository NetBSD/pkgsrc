# $NetBSD: Makefile,v 1.64 2014/05/09 07:36:58 wiz Exp $

DISTNAME=	bzr-2.5.1
CATEGORIES=	devel scm
MASTER_SITES=	https://launchpad.net/bzr/${PKGVERSION_NOREV:R}/${PKGVERSION_NOREV}/+download/

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://bazaar-vcs.org/
COMMENT=	Bazaar open source distributed version control system
LICENSE=	gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-expat>=0:../../textproc/py-expat
BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils
BUILD_DEPENDS+=		${PYPKGPREFIX}-pyrex>=0:../../lang/py-pyrex

USE_TOOLS+=		gmake msgfmt

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-pyrex, py-paramiko

REPLACE_PYTHON=		bzr bzrlib/weave.py
REPLACE_PYTHON+=		bzrlib/patiencediff.py bzrlib/_patiencediff_py.py
REPLACE_PYTHON+=		bzrlib/plugins/bash_completion/bashcomp.py
REPLACE_PYTHON+=		bzrlib/tests/ssl_certs/create_ssls.py

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
