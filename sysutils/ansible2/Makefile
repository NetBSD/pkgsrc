# $NetBSD: Makefile,v 1.3 2017/05/22 11:31:34 jperkin Exp $

DISTNAME=	ansible-2.3.0.0
CATEGORIES=	python sysutils
MASTER_SITES=	http://releases.ansible.com/ansible/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ansible.com/
COMMENT=	SSH-based configuration management, deployment, and task execution
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-crypto>=2.6:../../security/py-crypto

USE_TOOLS+=	gmake

PKG_SYSCONFSUBDIR=	ansible
EGDIR=			${PREFIX}/share/examples/ansible

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	docs/man/man1/*.1
SUBST_FILES.paths+=	examples/ansible.cfg examples/hosts
SUBST_FILES.paths+=	lib/ansible/constants.py
SUBST_FILES.paths+=	lib/ansible/cli/galaxy.py
SUBST_FILES.paths+=	lib/ansible/module_utils/urls.py
SUBST_FILES.paths+=	lib/ansible/modules/system/setup.py
SUBST_FILES.paths+=	lib/ansible/utils/module_docs_fragments/cnos.py
SUBST_FILES.paths+=	lib/ansible/utils/module_docs_fragments/openstack.py
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_SED.paths=	-e "s,/usr/share/ansible,${PREFIX}/share/ansible,g"
SUBST_SED.paths+=	-e "s,/etc/ansible,${PKG_SYSCONFDIR},g"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKG_SYSCONFDIR} ${EGDIR}
OWN_DIRS=		${PREFIX}/share/ansible

CONF_FILES=		${EGDIR}/ansible.cfg ${PKG_SYSCONFDIR}/ansible.cfg
CONF_FILES+=		${EGDIR}/hosts ${PKG_SYSCONFDIR}/hosts

post-install:
.for f in ansible-console.1 ansible-doc.1 ansible-galaxy.1 ansible-playbook.1 \
	  ansible-pull.1 ansible-vault.1 ansible.1
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/${f} \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor
.for f in ansible.cfg hosts
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${DESTDIR}/${EGDIR}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
