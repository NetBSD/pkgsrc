# $NetBSD: Makefile,v 1.6 2022/01/10 01:46:41 ryoon Exp $

DISTNAME=	icinga2-2.12.3
PKGREVISION=	4
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=icinga/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ef@math.uni-bonn.de
HOMEPAGE=	https://www.icinga.com/products/icinga-2/
COMMENT=	Monitoring system
LICENSE=	gnu-gpl-v2

ICINGA2_USER?=		icinga
ICINGA2_GROUP?=		icinga
ICINGA2_COMMAND_GROUP?=	icingacmd

PLUGINDIR=		${PREFIX}/libexec/nagios

PKG_USERS=		${ICINGA2_USER}:${ICINGA2_GROUP}
PKG_GROUPS=		${ICINGA2_GROUP} ${ICINGA2_COMMAND_GROUP}
PKG_USERS_VARS+=	ICINGA2_USER
PKG_GROUPS_VARS+=	ICINGA2_GROUP ICINGA2_COMMAND_GROUP
BUILD_DEFS+=		ICINGA2_USER ICINGA2_GROUP ICINGA2_COMMAND_GROUP VARBASE PKG_SYSCONFBASE

USE_LANGUAGES=	c c++ c++11
USE_CMAKE=	yes
USE_TOOLS+=	flex bison

PKG_RCD_SCRIPTS=	YES
RCD_SCRIPTS=		icinga2
FILES_SUBST+=		ICINGA2_USER=${ICINGA2_USER}
FILES_SUBST+=		ICINGA2_GROUP=${ICINGA2_GROUP} ICINGA2_COMMAND_GROUP=${ICINGA2_COMMAND_GROUP}
FILES_SUBST+=		NAGIOS_PLUGIN_STATE_DIRECTORY=${VARBASE}/spool/nagios
FILES_SUBST+=		RUNDIR=${RUNDIR}

PKG_SYSCONFSUBDIR=	icinga2
EGDIR_PARENT=		${PREFIX}/share/examples
EGDIR=			${EGDIR_PARENT}/icinga2
DOCDIR=			${PREFIX}/share/doc/icinga2
INSTALLATION_DIRS+=	${EGDIR} ${DOCDIR}
INSTALLATION_DIRS+=	${EGDIR_PARENT}/bash_completion.d
#! intall into BASHCOMPDIR=${PREFIX}/share/bash-completion/completions?
INSTALLATION_DIRS+=	${EGDIR}/conf.d
INSTALLATION_DIRS+=	${EGDIR}/features-available
INSTALLATION_DIRS+=	${EGDIR}/scripts
INSTALLATION_DIRS+=	${EGDIR}/zones.d

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

RUNDIR_PARENT=		${VARBASE}/run
RUNDIR=			${RUNDIR_PARENT}/icinga2

SPOOLDIR_PARENT=		${VARBASE}/spool
SPOOLDIR=			${SPOOLDIR_PARENT}/icinga2
PKG_HOME.${ICINGA2_USER}=	${SPOOLDIR}

# All the _PERMS values are chosen to mimic what icinga2.spec says

MAKE_DIRS+=		${VARBASE}/cache
OWN_DIRS_PERMS+=	${VARBASE}/cache/icinga2 ${ICINGA2_USER} ${ICINGA2_COMMAND_GROUP} 0750
MAKE_DIRS+=		${VARBASE}/log
OWN_DIRS_PERMS+=	${VARBASE}/log/icinga2 ${ICINGA2_USER} ${ICINGA2_COMMAND_GROUP} 0755 # spec: 0750
OWN_DIRS_PERMS+=	${VARBASE}/log/icinga2/crash ${ICINGA2_USER} ${ICINGA2_GROUP} 0750
.if !empty(PKG_OPTIONS:Micinga2-compat)
OWN_DIRS_PERMS+=	${VARBASE}/log/icinga2/compat ${ICINGA2_USER} ${ICINGA2_COMMAND_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/log/icinga2/archive ${ICINGA2_USER} ${ICINGA2_COMMAND_GROUP} 0750
.endif
MAKE_DIRS+=		${VARBASE}/lib
OWN_DIRS_PERMS+=	${VARBASE}/lib/icinga2 ${ICINGA2_USER} ${ICINGA2_COMMAND_GROUP} 0750
#OWN_DIRS+=		${VARBASE}/lib/icinga2/api
#OWN_DIRS+=		${VARBASE}/lib/icinga2/api/log
#OWN_DIRS+=		${VARBASE}/lib/icinga2/api/repository
#OWN_DIRS+=		${VARBASE}/lib/icinga2/api/zones
# These need to be created in the RC script since RUNDIR may reside on a tempfs
#MAKE_DIRS+=		${RUNDIR_PARENT}
#OWN_DIRS_PERMS+=	${RUNDIR} ${ICINGA2_USER} ${ICINGA2_COMMAND_GROUP} 0751 # spec: 0750
#OWN_DIRS_PERMS+=	${RUNDIR}/cmd ${ICINGA2_USER} ${ICINGA2_COMMAND_GROUP} 2750
MAKE_DIRS+=		${SPOOLDIR_PARENT}
OWN_DIRS_PERMS+=	${SPOOLDIR} ${ICINGA2_USER} ${ICINGA2_GROUP} 0750
.if !empty(PKG_OPTIONS:Micinga2-perfdata)
OWN_DIRS_PERMS+=	${SPOOLDIR}/perfdata ${ICINGA2_USER} ${ICINGA2_GROUP} 0770
.endif
OWN_DIRS_PERMS+=	${SPOOLDIR}/tmp ${ICINGA2_USER} ${ICINGA2_GROUP} 0750

#OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR} ${REAL_ROOT_USER} ${ICINGA2_GROUP} 0750
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/conf.d ${ICINGA2_USER} ${ICINGA2_GROUP} 0750
.for f in app commands downtimes groups hosts notifications services templates timeperiods users
CONF_FILES_PERMS+=	${EGDIR}/conf.d/${f}.conf ${PKG_SYSCONFDIR}/conf.d/${f}.conf ${ICINGA2_USER} ${ICINGA2_GROUP} 0640
.endfor
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/features-available ${ICINGA2_USER} ${ICINGA2_GROUP} 0750
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/features-enabled ${ICINGA2_USER} ${ICINGA2_GROUP} 0750
FEATURES=		api debuglog mainlog syslog
.if !empty(PKG_OPTIONS:Micinga2-checker)
FEATURES+=		checker
.endif
.if !empty(PKG_OPTIONS:Micinga2-compat)
FEATURES+=		command compatlog statusdata
.endif
.if !empty(PKG_OPTIONS:Micinga2-livestatus)
FEATURES+=		livestatus
.endif
.if !empty(PKG_OPTIONS:Micinga2-mysql)
FEATURES+=		ido-mysql
.endif
.if !empty(PKG_OPTIONS:Micinga2-notification)
FEATURES+=		notification
.endif
.if !empty(PKG_OPTIONS:Micinga2-perfdata)
FEATURES+=		elasticsearch gelf graphite influxdb opentsdb perfdata
.endif
.if !empty(PKG_OPTIONS:Micinga2-pgsql)
FEATURES+=		ido-pgsql
.endif
.for f in ${FEATURES}
CONF_FILES_PERMS+=	${EGDIR}/features-available/${f}.conf ${PKG_SYSCONFDIR}/features-available/${f}.conf ${ICINGA2_USER} ${ICINGA2_GROUP} 0640
.endfor
OWN_DIRS+=		${PKG_SYSCONFDIR}/scripts
.for f in mail-host-notification.sh mail-service-notification.sh
CONF_FILES_PERMS+=	${EGDIR}/scripts/${f} ${PKG_SYSCONFDIR}/scripts/${f} ${ICINGA2_USER} ${ICINGA2_GROUP} 0755
.endfor
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/zones.d ${ICINGA2_USER} ${ICINGA2_GROUP} 0750
.for f in constants.conf icinga2.conf zones.conf zones.d/README
CONF_FILES_PERMS+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f} ${ICINGA2_USER} ${ICINGA2_GROUP} 0640
.endfor
#OWN_DIRS+=		${PKG_SYSCONFDIR}/keys
#OWN_DIRS+=		${PKG_SYSCONFDIR}/pki

CMAKE_ARGS+=	-DICINGA2_USER=${ICINGA2_USER} -DICINGA2_GROUP=${ICINGA2_GROUP}
CMAKE_ARGS+=	-DICINGA2_GIT_VERSION_INFO=OFF
CMAKE_ARGS+=	-DICINGA2_COMMAND_GROUP=${ICINGA2_COMMAND_GROUP}
#CMAKE_ARGS+=	-DICINGA2_UNITY_BUILD=???	# Whether to perform a unity build; defaults to `ON`
#CMAKE_ARGS+=	-DICINGA2_LTO_BUILD=???		# Whether to use link time optimization (LTO); defaults to `OFF`
CMAKE_ARGS+=	-DICINGA2_PLUGINDIR=${PLUGINDIR}
CMAKE_ARGS+=	-DICINGA2_RUNDIR=${RUNDIR_PARENT}
CMAKE_ARGS+=	-DCMAKE_INSTALL_SYSCONFDIR=${PKG_SYSCONFBASE} # not PKG_SYSCONFDIR!
#CMAKE_ARGS+=	-DICINGA2_SYSCONFIGFILE=???	# Where to put the config file the initscript/systemd pulls it's dirs from; defaults to `CMAKE_INSTALL_PREFIX/etc/sysconfig/icinga2`
CMAKE_ARGS+=	-DCMAKE_INSTALL_LOCALSTATEDIR=${VARBASE}
# For ICINGA2_WITH_XXX see options.mk
CMAKE_ARGS+=	-DICINGA2_WITH_TESTS=OFF

# Avoid a name clash with Boost header on case-insensitive file systems.
# Remove outdated GNUInstallDirs.cmake.
post-extract:
	${MV} ${WRKSRC}/VERSION ${WRKSRC}/ICINGA2_VERSION
	${RM} ${WRKSRC}/third-party/cmake/GNUInstallDirs.cmake

# The configuration files are installed in etc/icinga2.  You can't tell CMAKE
# to put them elsewhere because the program and the config files contain
# references to the config dir.  So move them to share/examples after
# installation.
post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/* ${DESTDIR}${EGDIR}

CHECK_FILES_SKIP=	${PREFIX}/etc/bash_completion.d/icinga2
CHECK_FILES_SKIP+=	${PREFIX}/share/examples/icinga2/features-enabled/checker.conf
CHECK_FILES_SKIP+=	${PREFIX}/share/examples/icinga2/features-enabled/mainlog.conf
CHECK_FILES_SKIP+=	${PREFIX}/share/examples/icinga2/features-enabled/notification.conf

#CMAKE_ARGS+=	-DCMAKE_SKIP_BUILD_RPATH=FALSE
#CMAKE_ARGS+=	-DCMAKE_BUILD_WITH_INSTALL_RPATH=FALSE
#CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH=${PREFIX}/lib/icinga2
#CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=FALSE

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/icinga2

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
