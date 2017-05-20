# $NetBSD: Makefile,v 1.51 2017/05/20 11:30:27 adam Exp $

DISTNAME=	salt-2016.11.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=s/salt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://saltstack.org/
COMMENT=	Remote execution and configuration management system
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-msgpack-[0-9]*:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-requests>=2.5.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.3:../../www/py-tornado
# zeromq transport requirements
DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto
DEPENDS+=	${PYPKGPREFIX}-zmq>=2.1.9:../../net/py-zmq

.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py27"
DEPENDS+= ${PYPKGPREFIX}-futures-[0-9]*:../../devel/py-futures
.endif

BUILD_DEFS+=	VARBASE

PYSETUPARGS+=	--salt-base-file-roots-dir=${VARBASE}/salt/file-roots
PYSETUPARGS+=	--salt-base-pillar-roots-dir=${VARBASE}/salt/pillar-roots
PYSETUPARGS+=	--salt-base-master-roots-dir=${VARBASE}/salt/master-roots
PYSETUPARGS+=	--salt-cache-dir=${VARBASE}/cache/salt
PYSETUPARGS+=	--salt-config-dir=${PKG_SYSCONFDIR}
PYSETUPARGS+=	--salt-logs-dir=${VARBASE}/log/salt
PYSETUPARGS+=	--salt-pidfile-dir=${VARBASE}/run
PYSETUPARGS+=	--salt-sock-dir=${VARBASE}/run/salt

REPLACE_PYTHON=		*.py */*.py */*/*.py
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

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	pre-configure
SUBST_MESSAGE.fix-paths=Fixing hardcoded paths
SUBST_FILES.fix-paths=	conf/*
SUBST_FILES.fix-paths+=	doc/man/* salt/modules/munin.py setup.py
SUBST_FILES.fix-paths+=	salt/utils/rsax931.py salt/grains/core.py
SUBST_SED.fix-paths=	-e 's,/etc/salt,${PKG_SYSCONFDIR},g'
SUBST_SED.fix-paths+=	-e 's,/srv/salt,${VARBASE}/salt/file-roots,g'
SUBST_SED.fix-paths+=	-e 's,/srv/pillar,${VARBASE}/salt/pillar-roots,g'
SUBST_SED.fix-paths+=	-e 's,/etc/munin,${PKG_SYSCONFBASEDIR}/munin,g'
SUBST_SED.fix-paths+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.fix-paths+=	-e 's,/opt/local/lib,${PREFIX}/lib,g'
SUBST_SED.fix-paths+=	-e 's,/opt/local/etc,${PKG_SYSCONFBASEDIR},g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/master ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/conf/minion ${DESTDIR}${EGDIR}/

# Dependencies are documented at
# http://docs.saltstack.org/en/latest/topics/installation/index.html#dependencies
# Jinja2 is documented as an optional dependency, but it's small so we
# include it unconditionally.
#
# There's also an optional dependency on gcc, for Cython support, but
# we don't bother with that here.
#
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
