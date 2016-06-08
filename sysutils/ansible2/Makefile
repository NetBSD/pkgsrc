# $NetBSD: Makefile,v 1.1 2016/06/08 14:16:25 jperkin Exp $

DISTNAME=	ansible-2.1.0.0
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
SUBST_FILES.paths+=	contrib/inventory/*.py
SUBST_FILES.paths+=	docs/man/man1/*.1
SUBST_FILES.paths+=	examples/ansible.cfg examples/hosts
SUBST_FILES.paths+=	lib/ansible/*.py lib/ansible/*/*.py lib/ansible/*/*/*.py
SUBST_FILES.paths+=	lib/ansible/*/*/*/*.py
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_SED.paths=	-e "s,/usr/share/ansible,${PREFIX}/share/ansible,g"
SUBST_SED.paths+=	-e "s,/etc/ansible,${PKG_SYSCONFDIR},g"

SUBST_CLASSES+=		pybin
SUBST_STAGE.pybin=	pre-configure
SUBST_FILES.pybin=	Makefile
SUBST_MESSAGE.pybin=	Fixing path to PYTHONBIN.
SUBST_SED.pybin=	-e "s,PYTHON=python,PYTHON=${PYTHONBIN},"

REPLACE_PYTHON=		lib/ansible/*/*.py lib/ansible/*/*/*.py
REPLACE_PYTHON+=	lib/ansible/*/*/*/*.py lib/ansible/*/*/*/*/*.py
REPLACE_PYTHON+=	lib/ansible/*/*/*/*/*/*.py lib/ansible/*/*/*/*/*/*/*.py

MANPAGES=		ansible-doc.1 ansible-galaxy.1 ansible-playbook.1 \
			ansible-pull.1 ansible-vault.1 ansible.1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKG_SYSCONFDIR} ${EGDIR}
OWN_DIRS=		${PREFIX}/share/ansible

CONF_FILES=		${EGDIR}/ansible.cfg ${PKG_SYSCONFDIR}/ansible.cfg
CONF_FILES+=		${EGDIR}/hosts ${PKG_SYSCONFDIR}/hosts

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
