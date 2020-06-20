# $NetBSD: Makefile,v 1.33 2020/06/20 06:55:04 adam Exp $

DISTNAME=	ansible-2.9.10
CATEGORIES=	sysutils python
MASTER_SITES=	https://releases.ansible.com/ansible/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ansible.com/
COMMENT=	SSH-based configuration management, deployment, and task execution
LICENSE=	gnu-gpl-v3

PREV_PKGPATH=	sysutils/ansible2

DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_TOOLS+=	gmake

PKG_SYSCONFSUBDIR=	ansible
EGDIR=			${PREFIX}/share/examples/ansible

REPLACE_PYTHON=		test/lib/ansible_test/_data/*.py
REPLACE_PYTHON+=	test/lib/ansible_test/_data/*/*.py
REPLACE_PYTHON+=	test/lib/ansible_test/_data/*/*/*.py

CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/ansible_test/_data/requirements/sanity.ps1
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/ansible_test/_data/sanity/pslint/pslint.ps1
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/ansible_test/_data/sanity/validate-modules/validate_modules/ps_argspec.ps1

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	docs/man/man1/*.1
SUBST_FILES.paths+=	examples/ansible.cfg
SUBST_FILES.paths+=	examples/hosts
SUBST_FILES.paths+=	lib/ansible/config/base.yml
SUBST_FILES.paths+=	lib/ansible/module_utils/urls.py
SUBST_FILES.paths+=	lib/ansible/modules/system/setup.py
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_SED.paths=	-e "s,/usr/share/ansible,${PREFIX}/share/ansible,g"
SUBST_SED.paths+=	-e "s,/etc/ansible,${PKG_SYSCONFDIR},g"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKG_SYSCONFDIR} ${EGDIR}
OWN_DIRS=		${PREFIX}/share/ansible

CONF_FILES=		${EGDIR}/ansible.cfg ${PKG_SYSCONFDIR}/ansible.cfg
CONF_FILES+=		${EGDIR}/hosts ${PKG_SYSCONFDIR}/hosts

# Contains hardcoded paths to expected locations of package managers.
CHECK_WRKREF_SKIP+=	*/ansible/module_utils/facts/system/pkg_mgr.py

post-install:
.for f in ansible-console.1 ansible-doc.1 ansible-galaxy.1 ansible-inventory.1 \
	ansible-playbook.1 ansible-pull.1 ansible-vault.1 ansible.1
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor
.for f in ansible.cfg hosts
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${DESTDIR}/${EGDIR}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
