# $NetBSD: Makefile,v 1.18 2016/02/18 09:24:25 he Exp $

DISTNAME=	ansible-1.9.4
PKGREVISION=	2
#PKGNAME=   ${PYPKGPREFIX}-${DISTNAME} # XXX: for when package is py3x-ready
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
EGDIR=		${PREFIX}/share/examples/ansible

SUBST_CLASSES+=         prefix
SUBST_STAGE.prefix=     pre-configure
SUBST_FILES.prefix+=    docs/man/man1/ansible.1
SUBST_FILES.prefix+=    docs/man/man1/ansible.1.asciidoc.in
SUBST_FILES.prefix+=    docs/man/man1/ansible-galaxy.1
SUBST_FILES.prefix+=    docs/man/man1/ansible-galaxy.1.asciidoc.in
SUBST_FILES.prefix+=    docs/man/man1/ansible-playbook.1
SUBST_FILES.prefix+=    docs/man/man1/ansible-playbook.1.asciidoc.in
SUBST_FILES.prefix+=    examples/ansible.cfg examples/hosts
SUBST_FILES.prefix+=    lib/ansible/constants.py lib/ansible/callbacks.py
SUBST_FILES.prefix+=    lib/ansible/modules/core/system/ping.py
SUBST_FILES.prefix+=    lib/ansible/modules/core/system/setup.py
SUBST_FILES.prefix+=    lib/ansible/modules/extras/database/misc/riak.py
SUBST_FILES.prefix+=    lib/ansible/modules/extras/monitoring/nagios.py
SUBST_FILES.prefix+=    lib/ansible/modules/extras/packaging/os/pkgin.py
SUBST_FILES.prefix+=    plugins/README.md plugins/inventory/cobbler.py
SUBST_FILES.prefix+=    plugins/inventory/collins.py
SUBST_MESSAGE.prefix=   Fixing PREFIX path.
SUBST_SED.prefix=       -e "s,@PREFIX@,${PREFIX},"
SUBST_SED.prefix+=      -e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},"

SUBST_CLASSES+=         pythonbin
SUBST_STAGE.pythonbin=  pre-configure
SUBST_FILES.pythonbin=  Makefile
SUBST_MESSAGE.pythonbin=        Fixing path to PYTHONBIN.
SUBST_SED.pythonbin=    -e "s,PYTHON=python,PYTHON=${PYTHONBIN},"

PYTHON_VERSIONS_INCOMPATIBLE=   33 34 35 # py-paramiko

REPLACE_PYTHON=         lib/ansible/runner/action_plugins/synchronize.py
REPLACE_PYTHON+=        lib/ansible/utils/module_docs.py

MANPAGES=       ansible-doc.1 ansible-pull.1 ansible-galaxy.1 ansible-vault.1
MANPAGES+=      ansible-playbook.1 ansible.1

INSTALLATION_DIRS=      bin ${PKGMANDIR}/man1 ${PKG_SYSCONFDIR}/ansible
INSTALLATION_DIRS+=     ${EGDIR}/playbooks
INSTALLATION_DIRS+=     share/ansible/roles

CHECK_INTERPRETER_SKIP= share/ansible/*

MAKE_DIRS=		${PKG_SYSCONFDIR}/ansible ${PREFIX}/share/ansible
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
.for f in ${MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/${f} \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor
.for f in ansible.cfg hosts
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${DESTDIR}/${EGDIR}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
