# $NetBSD: Makefile,v 1.36 2016/02/09 14:23:04 wiz Exp $

DISTNAME=	salt-2015.8.5
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=s/salt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://saltstack.org/
COMMENT=	Remote execution and configuration management system
LICENSE=	apache-2.0

DEPENDS+= zeromq>=2.1.9:../../net/zeromq
DEPENDS+= ${PYPKGPREFIX}-zmq>=2.1.9:../../net/py-zmq
DEPENDS+= ${PYPKGPREFIX}-m2crypto-[0-9]*:../../security/py-m2crypto
DEPENDS+= ${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto
DEPENDS+= ${PYPKGPREFIX}-msgpack-[0-9]*:../../devel/py-msgpack
DEPENDS+= ${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+= ${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+= ${PYPKGPREFIX}-apache-libcloud>=0.14.1:../../net/py-apache-libcloud
DEPENDS+= ${PYPKGPREFIX}-requests>=2.5.0:../../devel/py-requests
DEPENDS+= ${PYPKGPREFIX}-tornado>=4.3:../../www/py-tornado

BUILD_DEFS+=	VARBASE

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-m2crypto

PYSETUPINSTALLARGS+=	--salt-root-dir=${PREFIX}
PYSETUPINSTALLARGS+=	--salt-config-dir=${PKG_SYSCONFDIR}
PYSETUPINSTALLARGS+=	--salt-cache-dir=${VARBASE}/cache/salt
PYSETUPINSTALLARGS+=	--salt-sock-dir=${VARBASE}/run/salt
PYSETUPINSTALLARGS+=	--salt-base-file-roots-dir=${PKG_SYSCONFDIR}/states
PYSETUPINSTALLARGS+=	--salt-base-pillar-roots-dir=${PKG_SYSCONFDIR}/pillar
PYSETUPINSTALLARGS+=	--salt-base-master-roots-dir=${PKG_SYSCONFDIR}/salt-master
PYSETUPINSTALLARGS+=	--salt-logs-dir=${VARBASE}/log/salt
PYSETUPINSTALLARGS+=	--salt-pidfile-dir=${VARBASE}/run

REPLACE_PYTHON=	*.py */*.py */*/*.py

RCD_SCRIPTS+=		salt_master salt_minion
SMF_INSTANCES=		master minion
FILES_SUBST+=		PYTHON=${PYTHONBIN:Q}

PKG_SYSCONFSUBDIR=	salt

EGDIR=			${PREFIX}/share/examples/salt
INSTALLATION_DIRS+= 	${EGDIR}
CONF_FILES+=		${EGDIR}/master ${PKG_SYSCONFDIR}/master
CONF_FILES+=		${EGDIR}/minion ${PKG_SYSCONFDIR}/minion

OWN_DIRS+=		${PKG_SYSCONFDIR}/states ${PKG_SYSCONFDIR}/pillar
OWN_DIRS+=		${PKG_SYSCONFDIR}/salt-master
OWN_DIRS+=		${VARBASE}/cache/salt ${VARBASE}/run/salt
OWN_DIRS+=		${VARBASE}/log/salt

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	pre-configure
SUBST_MESSAGE.fix-paths=Fixing hardcoded paths
SUBST_FILES.fix-paths=	conf/*
SUBST_FILES.fix-paths+=	doc/man/* salt/modules/munin.py setup.py
SUBST_FILES.fix-paths+=	salt/utils/rsax931.py salt/grains/core.py
SUBST_SED.fix-paths=	-e 's,/etc/salt,${PKG_SYSCONFDIR},g'
SUBST_SED.fix-paths+=	-e 's,/srv/salt,${PKG_SYSCONFDIR}/states,g'
SUBST_SED.fix-paths+=	-e 's,/srv/pillar,${PKG_SYSCONFDIR}/pillar,g'
SUBST_SED.fix-paths+=	-e 's,/etc/munin,${PKG_SYSCONFBASEDIR}/munin,g'
SUBST_SED.fix-paths+=	-e 's,share/man,man,g'
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
