# $NetBSD: Makefile,v 1.26 2019/11/02 15:18:34 rillig Exp $

DISTNAME=	ansible-1.9.4
PKGREVISION=	2
#PKGNAME=	${PYPKGPREFIX}-${DISTNAME} # XXX: for when package is py3x-ready
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
AUTO_MKDIRS=	yes
EGDIR=		${PREFIX}/share/examples/ansible

SUBST_CLASSES+=		dirs
SUBST_STAGE.dirs=	pre-configure
SUBST_FILES.dirs+=	docs/man/man1/ansible.1
SUBST_FILES.dirs+=	docs/man/man1/ansible.1.asciidoc.in
SUBST_FILES.dirs+=	docs/man/man1/ansible-galaxy.1
SUBST_FILES.dirs+=	docs/man/man1/ansible-galaxy.1.asciidoc.in
SUBST_FILES.dirs+=	docs/man/man1/ansible-playbook.1
SUBST_FILES.dirs+=	docs/man/man1/ansible-playbook.1.asciidoc.in
SUBST_FILES.dirs+=	examples/ansible.cfg examples/hosts
SUBST_FILES.dirs+=	lib/ansible/constants.py lib/ansible/callbacks.py
SUBST_FILES.dirs+=	lib/ansible/modules/core/system/ping.py
SUBST_FILES.dirs+=	lib/ansible/modules/core/system/setup.py
SUBST_FILES.dirs+=	lib/ansible/modules/extras/database/misc/riak.py
SUBST_FILES.dirs+=	lib/ansible/modules/extras/monitoring/nagios.py
SUBST_FILES.dirs+=	lib/ansible/modules/extras/packaging/os/pkgin.py
SUBST_FILES.dirs+=	plugins/README.md plugins/inventory/cobbler.py
SUBST_FILES.dirs+=	plugins/inventory/collins.py
SUBST_VARS.dirs=	PREFIX PKG_SYSCONFBASE PKG_SYSCONFDIR

SUBST_CLASSES+=			pythonbin
SUBST_STAGE.pythonbin=		pre-configure
SUBST_FILES.pythonbin=		Makefile
SUBST_MESSAGE.pythonbin=	Fixing path to PYTHONBIN.
SUBST_SED.pythonbin=		-e "s,PYTHON=python,PYTHON=${PYTHONBIN},"

PYTHON_VERSIONS_ACCEPTED=	27 # py-paramiko

REPLACE_PYTHON=		lib/ansible/runner/action_plugins/synchronize.py
REPLACE_PYTHON+=	lib/ansible/utils/module_docs.py

INSTALLATION_DIRS=	${EGDIR}/playbooks share/ansible/roles

MAKE_DIRS=		${PREFIX}/share/ansible
MAKE_DIRS+=		${PREFIX}/share/ansible/ansible_plugins
MAKE_DIRS+=		${PREFIX}/share/ansible/ansible_plugins/action_plugins
MAKE_DIRS+=		${PREFIX}/share/ansible/ansible_plugins/callback_plugins
MAKE_DIRS+=		${PREFIX}/share/ansible/ansible_plugins/connection_plugins
MAKE_DIRS+=		${PREFIX}/share/ansible/ansible_plugins/lookup_plugins
MAKE_DIRS+=		${PREFIX}/share/ansible/ansible_plugins/vars_plugins
MAKE_DIRS+=		${PREFIX}/share/ansible/ansible_plugins/filter_plugins

pre-install:
	find ${WRKSRC} -name \*.orig -exec rm {} \;

post-install:
	cd ${WRKSRC}/docs/man/man1 && \
	${INSTALL_MAN} ./*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	cd ${WRKSRC}/examples && \
	${INSTALL_DATA} ansible.cfg hosts ${DESTDIR}/${EGDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
