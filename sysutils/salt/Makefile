# $NetBSD: Makefile,v 1.87 2024/12/26 22:16:45 adam Exp $

.include "Makefile.common"

COMMENT=	Remote execution and configuration management system

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

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
CHECK_WRKREF_SKIP+=	*/smartos.*

CHECK_PORTABILITY_SKIP+=	pkg/*/* pkg/*/*/*

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/master ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/conf/minion ${DESTDIR}${EGDIR}/

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
