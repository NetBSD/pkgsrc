# $NetBSD: Makefile,v 1.19 2024/01/07 16:13:43 rhialto Exp $

DISTNAME=	breezy-3.3.4
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	https://launchpad.net/brz/${PKGVERSION_NOREV:R}/${PKGVERSION_NOREV}/+download/

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://breezy-vcs.org/
COMMENT=	Friendly distributed version control system
LICENSE=	gnu-gpl-v2

# Seems to be used in all cases now:
TOOL_DEPENDS+=		${PYPKGPREFIX}-cython>=0.29:../../devel/py-cython
DEPENDS+=		${PYPKGPREFIX}-configobj>0:../../devel/py-configobj
DEPENDS+=		${PYPKGPREFIX}-dulwich>=0.20.23:../../devel/py-dulwich
DEPENDS+=		${PYPKGPREFIX}-fastbencode>=0.0.9:../../converters/py-fastbencode
DEPENDS+=		${PYPKGPREFIX}-fastimport>0:../../devel/py-fastimport
DEPENDS+=		${PYPKGPREFIX}-merge3>=0.0.14:../../textproc/py-merge3
DEPENDS+=		${PYPKGPREFIX}-patiencediff>=0.2.2:../../textproc/py-patiencediff
DEPENDS+=		${PYPKGPREFIX}-setuptools-rust>=1.8.1:../../devel/py-setuptools-rust
DEPENDS+=		${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml
# Not yet packaged; only needed for lp: shortcuts.
#DEPENDS+=		${PYPKGPREFIX}-launchpadlib>=1.6.3:../../devel/py-launchpadlib
TEST_DEPENDS+=		${PYPKGPREFIX}-testtools>=0:../../devel/py-testtools

USE_TOOLS+=		gmake
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

PYTHON_VERSIONS_INCOMPATIBLE=	27 312

# Prevent setup.py from building breezy/main.rs; use console_script instead.
MAKE_ENV+=		CIBUILDWHEEL=1

REPLACE_PYTHON+=	breezy/git/bzr-receive-pack
REPLACE_PYTHON+=	breezy/git/bzr-upload-pack
REPLACE_PYTHON+=	breezy/git/git-remote-bzr
REPLACE_PYTHON+=	breezy/git/git_remote_helper.py
REPLACE_PYTHON+=	breezy/plugins/bash_completion/bashcomp.py
REPLACE_PYTHON+=	breezy/tests/ssl_certs/create_ssls.py
REPLACE_PYTHON+=	breezy/version_info_formats/format_python.py
REPLACE_PYTHON+=	brz
REPLACE_PYTHON+=	contrib/brz_access

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	Fix python path for test case.
SUBST_STAGE.python=	post-extract
SUBST_FILES.python+=	Makefile
SUBST_SED.python+=	-e 's,=python3,=${PYTHONBIN},'

# If we were to build the rust version of brz, it needs RPATH for
# finding -lpython3...
post-extract:
	${ECHO} 'fn main() { println!("cargo:rustc-link-arg-bins=${COMPILER_RPATH_FLAG},${PREFIX}/lib"); } ' > ${WRKSRC}/build.rs

post-build:
	cd ${WRKSRC} && ${PYTHONBIN} tools/generate_docs.py man

post-install:
	cd ${WRKSRC} && ${INSTALL_MAN} brz.1 breezy/git/git-remote-bzr.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ./target/release/brz selftest -v

.include "cargo-depends.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
