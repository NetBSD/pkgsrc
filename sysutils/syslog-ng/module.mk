# $NetBSD: module.mk,v 1.3 2021/09/17 09:39:54 wiz Exp $
# used by sysutils/py-syslog-ng/Makefile
# used by sysutils/syslog-ng-amqp/Makefile
# used by sysutils/syslog-ng-curl/Makefile
# used by sysutils/syslog-ng-geoip2/Makefile
# used by sysutils/syslog-ng-mongodb/Makefile
# used by sysutils/syslog-ng-redis/Makefile
# used by sysutils/syslog-ng-snmp/Makefile
# used by sysutils/syslog-ng-smtp/Makefile
# used by sysutils/syslog-ng-sql/Makefile

.include "../../sysutils/syslog-ng/Makefile.common"

PKGNAME?=	${DISTNAME:S/ng/ng-${SYSLOG_MOD}/}

DEPENDS+=	syslog-ng-${PKGVERSION_NOREV}{nb*,}:../../sysutils/syslog-ng

CONFIGURE_ARGS+=	--enable-${SYSLOG_MOD}

SYSLOG_MOD_DIR?=	${SYSLOG_MOD}
SYSLOG_MOD_TARGET?=	${SYSLOG_MOD_DIR}
BUILD_TARGET?=		modules/${SYSLOG_MOD_DIR}/lib${SYSLOG_MOD_TARGET}.la

# Avoid building common stuff
MAKE_FLAGS+=		MODULE_DEPS_LIBS=""

INSTALL_TARGET=		install-moduleLTLIBRARIES
INSTALL_MAKE_FLAGS+=	lib_LTLIBRARIES=""
INSTALL_MAKE_FLAGS+=	module_LTLIBRARIES=${BUILD_TARGET}

INSTALLATION_DIRS=	lib/syslog-ng
