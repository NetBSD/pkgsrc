# $NetBSD: Makefile,v 1.18 2014/05/09 07:37:16 wiz Exp $

PKGNAME=		rabbitmq-${RMQ_VERSION}
DISTNAME=		rabbitmq-server-${RMQ_VERSION}
CATEGORIES=		net
MASTER_SITES=		http://www.rabbitmq.com/releases/rabbitmq-server/v${RMQ_VERSION}/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://www.rabbitmq.com/server.html
COMMENT=		Implementation of AMQP that provides robust messaging for applications
LICENSE=		mpl-1.1

USE_TOOLS+=		bash:run coreutils gmake unzip zip

MAKE_JOBS_SAFE=		no

BUILD_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto
DEPENDS+=		coreutils-[0-9]*:../../sysutils/coreutils
DEPENDS+=		${PYPKGPREFIX}-simplejson>=2:../../converters/py-simplejson

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 3.2.2

.include "version.mk"
.include "../../lang/python/pyversion.mk"

BUILD_DEFS+=		VARBASE

.include		"../../mk/bsd.prefs.mk"

RMQ_USER?=		rabbitmq
RMQ_GROUP?=		${RMQ_USER}
RMQ_SHELL?=		${TOOLS_PATH.bash}
RMQ_DIR?=		${VARBASE}/db/rabbitmq
RMQ_LOG?=		${VARBASE}/log/rabbitmq

OWN_DIRS+=		${RMQ_DIR} ${RMQ_LOG}
OWN_DIRS_PERMS+=	${RMQ_DIR} ${RMQ_USER} ${RMQ_GROUP} 0770
OWN_DIRS_PERMS+=	${RMQ_LOG} ${RMQ_USER} ${RMQ_GROUP} 0770

PKG_GROUPS+=		${RMQ_GROUP}
PKG_USERS+=		${RMQ_USER}:${RMQ_GROUP}
PKG_GECOS.${RMQ_USER}=	RabbitMQ Server User
PKG_HOME.${RMQ_USER}=	${RMQ_DIR}
PKG_SHELL.${RMQ_USER}=	${RMQ_SHELL}

PKG_SYSCONFSUBDIR=	${PKGBASE}
CONF_FILES+=		share/examples/rabbitmq/rabbitmq-env.conf \
			  ${PKG_SYSCONFDIR}/rabbitmq-env.conf
CONF_FILES+=		share/examples/rabbitmq/rabbitmq.config.example \
			  ${PKG_SYSCONFDIR}/rabbitmq.config

FILES_SUBST+=		RMQ_USER=${RMQ_USER}
FILES_SUBST+=		RMQ_GROUP=${RMQ_GROUP}
FILES_SUBST+=		RMQ_DIR=${RMQ_DIR}

INSTALLATION_DIRS+=	share/examples/rabbitmq

SCRIPTS_DIR=		${WRKSRC}/scripts

PLIST_SUBST+=		RMQ_VERSION=${RMQ_VERSION}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting standard paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	${SCRIPTS_DIR}/rabbitmqctl ${SCRIPTS_DIR}/rabbitmq-env
SUBST_FILES.paths+=	${SCRIPTS_DIR}/rabbitmq-plugins ${SCRIPTS_DIR}/rabbitmq-server
SUBST_FILES.paths+=	${SCRIPTS_DIR}/rabbitmq-defaults
SUBST_SED.paths=	-e 's|/etc/rabbitmq|${PKG_SYSCONFDIR}|g'
SUBST_SED.paths+=	-e 's|/var/lib|${VARBASE}/db|g'
SUBST_SED.paths+=	-e 's|/var/log|${VARBASE}/log|g'
SUBST_SED.paths+=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.paths+=	-e 's|erl|${PREFIX}/bin/erl|g'
SUBST_SED.paths+=	-e 's|readlink|${PREFIX}/bin/greadlink|g'

REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmqctl
REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmq-env
REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmq-server

MAKE_ENV+=		TARGET_DIR="${DESTDIR}${PREFIX}/lib/erlang/lib/rabbitmq_server-${RMQ_VERSION}"
MAKE_ENV+=		SBIN_DIR="${DESTDIR}${PREFIX}/sbin/"
MAKE_ENV+=		MAN_DIR="${DESTDIR}${PREFIX}/man"
MAKE_ENV+=		DOC_INSTALL_DIR="${DESTDIR}${PREFIX}/share/examples/rabbitmq"
MAKE_ENV+=		RMQ_VERSION=${RMQ_VERSION}
MAKE_ENV+=		MAKE_SHELL="${RMQ_SHELL}"
MAKE_ENV+=		GIT_SSL_NO_VERIFY=true

INSTALL_ENV+=		TARGET_DIR="${DESTDIR}${PREFIX}/lib/erlang/lib/rabbitmq_server-${RMQ_VERSION}"
INSTALL_ENV+=		SBIN_DIR="${DESTDIR}${PREFIX}/sbin/"
INSTALL_ENV+=		MAN_DIR="${DESTDIR}${PREFIX}/man"
INSTALL_ENV+=		DOC_INSTALL_DIR="${DESTDIR}${PREFIX}/share/examples/rabbitmq"
INSTALL_ENV+=		RMQ_VERSION=${RMQ_VERSION}
INSTALL_ENV+=		MAKE_SHELL="${RMQ_SHELL}"

REPLACE_PYTHON+=	calculate-relative
REPLACE_PYTHON+=	plugins-src/rabbitmq-amqp1.0/codegen.py

post-install:
	${INSTALL_DATA} ${FILESDIR}/rabbitmq-env.conf ${DESTDIR}${PREFIX}/share/examples/rabbitmq/rabbitmq-env.conf

.include "../../lang/erlang/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
