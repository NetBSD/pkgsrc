# $NetBSD: Makefile,v 1.5 2022/07/25 06:29:57 adam Exp $

DISTNAME=	ansible-core-2.13.2
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ansible-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ansible.com/
COMMENT=	SSH-based configuration management, deployment, and task execution
LICENSE=	gnu-gpl-v3

CONFLICTS+=	ansible<2.10

DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-resolvelib>=0.5.3:../../devel/py-resolvelib
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_TOOLS+=	gmake

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

PKG_SYSCONFSUBDIR=	ansible
EGDIR=			${PREFIX}/share/examples/ansible

REPLACE_PYTHON=		test/lib/ansible_test/_data/*.py
REPLACE_PYTHON+=	test/lib/ansible_test/_data/*/*.py
REPLACE_PYTHON+=	test/lib/ansible_test/_data/*/*/*.py
REPLACE_PYTHON+=	test/lib/ansible_test/_util/*/*/*.py

CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/ansible_test/_data/requirements/sanity.ps1
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/ansible_test/_data/sanity/pslint/pslint.ps1
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/ansible_test/_data/sanity/validate-modules/validate_modules/ps_argspec.ps1

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	examples/hosts
SUBST_FILES.paths+=	lib/ansible/config/base.yml
SUBST_FILES.paths+=	lib/ansible/module_utils/urls.py
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_SED.paths=	-e "s,/usr/share/ansible,${PREFIX}/share/ansible,g"
SUBST_SED.paths+=	-e "s,/etc/ansible,${PKG_SYSCONFDIR},g"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EGDIR}
OWN_DIRS=		${PREFIX}/share/ansible

CONF_FILES=		${EGDIR}/ansible.cfg ${PKG_SYSCONFDIR}/ansible.cfg
CONF_FILES+=		${EGDIR}/hosts ${PKG_SYSCONFDIR}/hosts

# Contains hardcoded paths to expected locations of package managers.
CHECK_WRKREF_SKIP+=	*/ansible/module_utils/facts/system/pkg_mgr.py

post-install:
.for f in ansible.cfg hosts
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${DESTDIR}/${EGDIR}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
