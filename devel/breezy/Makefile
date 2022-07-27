# $NetBSD: Makefile,v 1.13 2022/07/27 18:52:41 rhialto Exp $

DISTNAME=	breezy-3.2.2
PKGREVISION=	2
CATEGORIES=	devel scm
MASTER_SITES=	https://launchpad.net/brz/${PKGVERSION_NOREV:R}/${PKGVERSION_NOREV}/+download/

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://breezy-vcs.org/
COMMENT=	Friendly distributed version control system
LICENSE=	gnu-gpl-v2

# For building from repo instead of release tarball:
#BUILD_DEPENDS+=	${PYPKGPREFIX}-cython>=0:../../devel/py-cython
DEPENDS+=		${PYPKGPREFIX}-configobj>0:../../devel/py-configobj
DEPENDS+=		${PYPKGPREFIX}-dulwich>=0.20.23:../../devel/py-dulwich
DEPENDS+=		${PYPKGPREFIX}-fastbencode>=0.0.9:../../converters/py-fastbencode
DEPENDS+=		${PYPKGPREFIX}-fastimport>0:../../devel/py-fastimport
DEPENDS+=		${PYPKGPREFIX}-patiencediff>=0.2.2:../../textproc/py-patiencediff
DEPENDS+=		${PYPKGPREFIX}-six>0:../../lang/py-six
# Not yet packaged; only needed for lp: shortcuts.
#DEPENDS+=		${PYPKGPREFIX}-launchpadlib>=1.6.3:../../devel/py-launchpadlib
TEST_DEPENDS+=		${PYPKGPREFIX}-testtools>=0:../../devel/py-testtools

USE_TOOLS+=		gmake msgfmt

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

REPLACE_PYTHON+=	breezy/git/bzr-receive-pack
REPLACE_PYTHON+=	breezy/git/bzr-upload-pack
REPLACE_PYTHON+=	breezy/git/git-remote-bzr
REPLACE_PYTHON+=	breezy/git/git_remote_helper.py
REPLACE_PYTHON+=	breezy/plugins/bash_completion/bashcomp.py
REPLACE_PYTHON+=	breezy/tests/ssl_certs/create_ssls.py
REPLACE_PYTHON+=	breezy/version_info_formats/format_python.py
REPLACE_PYTHON+=	brz
REPLACE_PYTHON+=	contrib/brz_access
#REPLACE_PYTHON+=	tools/*.py tools/subunit-sum tools/time_graph.py

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	Fix python path for test case.
SUBST_STAGE.python=	post-extract
SUBST_FILES.python+=	Makefile
SUBST_SED.python+=	-e 's,=python,=${PYTHONBIN},'

post-build:
	cd ${WRKSRC} && ${PYTHONBIN} tools/generate_docs.py man

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ./brz selftest -v

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
