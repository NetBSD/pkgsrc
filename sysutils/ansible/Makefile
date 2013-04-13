# $NetBSD: Makefile,v 1.7 2013/04/13 17:51:57 riz Exp $
#

DISTNAME=	ansible-1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://ansible.cc/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ansible.cc/
COMMENT=	SSH-based configuration management, deployment, and task execution
LICENSE=	gnu-gpl-v3

EGDIR=		${PREFIX}/share/examples/ansible

#USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	docs/man/man1/ansible-playbook.1
SUBST_FILES.prefix+=	docs/man/man1/ansible.1
SUBST_FILES.prefix+=	examples/ansible.cfg
SUBST_FILES.prefix+=	lib/ansible/constants.py
SUBST_SED.prefix=	-e "s,@PREFIX@,${PREFIX},"
SUBST_SED.prefix+=	-e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},"

SUBST_CLASSES+=		localbase
SUBST_STAGE.localbase=	pre-configure
SUBST_FILES.localbase=	\
			lib/ansible/callbacks.py \
			library/mysql_db \
			library/ping \
			library/pkgin \
			library/raw \
			library/setup \
			library/slurp \
			library/virt
SUBST_SED.localbase=	-e "s,@LOCALBASE@,${LOCALBASE},"

SUBST_CLASSES+=		pythonbin
SUBST_STAGE.pythonbin=	pre-configure
SUBST_FILES.pythonbin=	Makefile
SUBST_FILES.pythonbin=	-e "s,@PYTHONBIN@,${PYTHONBIN},"

MANPAGES=	ansible-doc.1 ansible-pull.1 ansible-playbook.1 ansible.1

DEPENDS+=		${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=		${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=		${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man3
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/ansible ${EGDIR}/playbooks

CHECK_INTERPRETER_SKIP=	share/ansible/*

pre-install:
	find ${WRKSRC} -name \*.orig -exec rm {} \;

post-install:
.for f in ${MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/${f} \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.endfor
	${INSTALL_MAN} ${WRKSRC}/docs/man/man3/* \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/
.for f in ansible.cfg hosts
	${INSTALL_DATA} ${WRKSRC}/examples/${f} \
	    ${DESTDIR}/${EGDIR}
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}/${EGDIR}/playbooks
	for f in ${WRKSRC}/examples/playbooks/*.yml; do \
		${INSTALL_DATA} $$f ${DESTDIR}/${EGDIR}/playbooks; \
	done
.for f in filter_plugins handlers tasks templates vars
	${INSTALL_DATA_DIR} ${DESTDIR}/${EGDIR}/playbooks/${f}
	for g in ${WRKSRC}/examples/playbooks/${f}/*; do \
	    ${INSTALL_DATA} $$g ${DESTDIR}/${EGDIR}/playbooks/${f}; \
	done
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
