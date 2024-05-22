# $NetBSD: Makefile,v 1.32 2024/05/22 04:57:28 adam Exp $

DISTNAME=	ansible_core-2.17.0
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ansible-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ansible.com/
COMMENT=	SSH-based configuration management, deployment, and task execution
LICENSE=	gnu-gpl-v3

CONFLICTS+=	ansible<2.10

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=66.1.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-resolvelib>=0.5.3:../../devel/py-resolvelib
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml

USE_TOOLS+=	gmake

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=5.0:../../devel/py-importlib-resources
.endif

REPLACE_PYTHON=		test/lib/ansible_test/_data/*.py
REPLACE_PYTHON+=	test/lib/ansible_test/_data/*/*.py
REPLACE_PYTHON+=	test/lib/ansible_test/_data/*/*/*.py
REPLACE_PYTHON+=	test/lib/ansible_test/_util/*/*/*.py

CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/ansible_test/_data/requirements/sanity.ps1
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/ansible_test/_data/sanity/pslint/pslint.ps1
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/ansible_test/_data/sanity/validate-modules/validate_modules/ps_argspec.ps1

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	lib/ansible/config/base.yml
SUBST_FILES.paths+=	lib/ansible/module_utils/urls.py
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_SED.paths=	-e "s,/usr/share/ansible,${PREFIX}/share/ansible,g"
SUBST_SED.paths+=	-e "s,/etc/ansible,${PKG_SYSCONFDIR},g"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EGDIR}
OWN_DIRS=		${PREFIX}/share/ansible

# Contains hardcoded paths to expected locations of package managers.
CHECK_WRKREF_SKIP+=	*/ansible/module_utils/facts/system/pkg_mgr.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/python/tool.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
