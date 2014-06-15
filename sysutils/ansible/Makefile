# $NetBSD: Makefile,v 1.12 2014/06/15 00:54:26 rodent Exp $

DISTNAME=	ansible-1.6.3
#PKGNAME=	${PYPKGPREFIX}-${DISTNAME} # XXX: for when package is py3x-ready
CATEGORIES=	python sysutils
MASTER_SITES=	http://releases.ansible.com/ansible/
MASTER_SITES+=	https://pypi.python.org/packages/source/a/ansible/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ansibleworks.com/
COMMENT=	SSH-based configuration management, deployment, and task execution
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-crypto>=2.6:../../security/py-crypto

USE_TOOLS+=	gmake
EGDIR=		${PREFIX}/share/examples/ansible

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	examples/ansible.cfg lib/ansible/callbacks.py
SUBST_FILES.prefix+=	lib/ansible/constants.py library/packaging/pkgin
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_SED.prefix=	-e "s,@PREFIX@,${PREFIX},"
SUBST_SED.prefix+=	-e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},"

SUBST_CLASSES+=		pythonbin
SUBST_STAGE.pythonbin=	pre-configure
SUBST_FILES.pythonbin=	Makefile
SUBST_MESSAGE.pythonbin=	Fixing path to PYTHONBIN.
SUBST_SED.pythonbin=	-e "s,PYTHON=python,PYTHON=${PYTHONBIN},"

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-paramiko

REPLACE_PYTHON+=	lib/ansible/runner/action_plugins/synchronize.py
REPLACE_PYTHON+=	lib/ansible/utils/module_docs.py

MANPAGES=	ansible-doc.1 ansible-pull.1 ansible-galaxy.1 ansible-vault.1
MANPAGES+=	ansible-playbook.1 ansible.1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKG_SYSCONFDIR}/ansible
INSTALLATION_DIRS+=	${EGDIR}/playbooks

CHECK_INTERPRETER_SKIP=	share/ansible/*

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
