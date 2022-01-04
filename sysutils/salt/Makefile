# $NetBSD: Makefile,v 1.76 2022/01/04 20:54:50 wiz Exp $

DISTNAME=	salt-3004
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=s/salt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://saltstack.org/
COMMENT=	Remote execution and configuration management system
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.9.8:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-distro>=1.0.1:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.5.6:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.0.0:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-requests>=2.5.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-zmq>=19.0.2:../../net/py-zmq

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILD_DEFS+=	VARBASE

PYSETUPARGS+=	--salt-base-file-roots-dir=${VARBASE}/salt/file-roots
PYSETUPARGS+=	--salt-base-pillar-roots-dir=${VARBASE}/salt/pillar-roots
PYSETUPARGS+=	--salt-base-master-roots-dir=${VARBASE}/salt/master-roots
PYSETUPARGS+=	--salt-cache-dir=${VARBASE}/cache/salt
PYSETUPARGS+=	--salt-config-dir=${PKG_SYSCONFDIR}
PYSETUPARGS+=	--salt-logs-dir=${VARBASE}/log/salt
PYSETUPARGS+=	--salt-pidfile-dir=${VARBASE}/run
PYSETUPARGS+=	--salt-sock-dir=${VARBASE}/run/salt

REPLACE_SH=		salt/templates/git/ssh-id-wrapper

RCD_SCRIPTS+=		salt_master salt_minion salt_syndic
SMF_INSTANCES=		api master minion
FILES_SUBST+=		PYTHON=${PYTHONBIN:Q}

PKG_SYSCONFSUBDIR=	salt

EGDIR=			${PREFIX}/share/examples/salt
INSTALLATION_DIRS+=	${EGDIR}
CONF_FILES+=		${EGDIR}/master ${PKG_SYSCONFDIR}/master
CONF_FILES+=		${EGDIR}/minion ${PKG_SYSCONFDIR}/minion

OWN_DIRS+=		${VARBASE}/salt/file-roots
OWN_DIRS+=		${VARBASE}/salt/pillar-roots
OWN_DIRS+=		${VARBASE}/salt/master-roots
OWN_DIRS+=		${VARBASE}/cache/salt ${VARBASE}/run/salt
OWN_DIRS+=		${VARBASE}/log/salt

SUBST_CLASSES+=		fix-path
SUBST_STAGE.fix-path=	pre-configure
SUBST_MESSAGE.fix-path=	Fixing hardcoded paths
SUBST_FILES.fix-path=	conf/*
SUBST_FILES.fix-path+=	doc/man/* salt/modules/munin.py setup.py
SUBST_FILES.fix-path+=	salt/utils/rsax931.py salt/grains/core.py
SUBST_SED.fix-path=	-e 's,/etc/salt,${PKG_SYSCONFDIR},g'
SUBST_SED.fix-path+=	-e 's,/srv/salt,${VARBASE}/salt/file-roots,g'
SUBST_SED.fix-path+=	-e 's,/srv/pillar,${VARBASE}/salt/pillar-roots,g'
SUBST_SED.fix-path+=	-e 's,/etc/munin,${PKG_SYSCONFBASEDIR}/munin,g'
SUBST_SED.fix-path+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.fix-path+=	-e 's,/opt/local/lib,${PREFIX}/lib,g'
SUBST_SED.fix-path+=	-e 's,/opt/local/etc,${PKG_SYSCONFBASEDIR},g'
SUBST_SED.fix-path+=	-e 's,/var/run,${VARBASE}/run,g'
SUBST_SED.fix-path+=	-e 's,/var/cache,${VARBASE}/cache,g'
SUBST_SED.fix-path+=	-e 's,/var/log,${VARBASE}/log,g'
SUBST_NOOP_OK.fix-path=	yes

# Contains hardcoded paths to find installed libraries.
CHECK_WRKREF_SKIP+=	*/salt/utils/rsax931.py

CHECK_PORTABILITY_SKIP+=	pkg/*/* pkg/*/*/*

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/master ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/conf/minion ${DESTDIR}${EGDIR}/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
