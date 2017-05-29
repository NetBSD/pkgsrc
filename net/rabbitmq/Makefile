# $NetBSD: Makefile,v 1.30 2017/05/29 13:16:11 fhajny Exp $

DISTNAME=		rabbitmq-server-3.6.10
PKGNAME=		${DISTNAME:S/-server//}
CATEGORIES=		net
MASTER_SITES=		http://www.rabbitmq.com/releases/rabbitmq-server/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://www.rabbitmq.com/server.html
COMMENT=		Implementation of AMQP that provides robust messaging for applications
LICENSE=		mpl-1.1

USE_TOOLS+=		bash:run gmake unzip zip

BUILD_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
BUILD_DEPENDS+=		rsync-[0-9]*:../../net/rsync
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto
DEPENDS+=		${PYPKGPREFIX}-simplejson>=2:../../converters/py-simplejson

BUILD_DEFS+=		VARBASE

.include		"../../mk/bsd.prefs.mk"

RMQ_USER?=		rabbitmq
RMQ_GROUP?=		${RMQ_USER}
RMQ_SHELL?=		${TOOLS_PATH.bash}
RMQ_DIR?=		${VARBASE}/db/rabbitmq
RMQ_LOG?=		${VARBASE}/log/rabbitmq

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

RABBITMQ_HOME=		${PREFIX}/lib/erlang/lib/rabbitmq_server-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	share/examples/rabbitmq

SCRIPTS_DIR=		${WRKSRC}/deps/rabbit/scripts

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting standard paths
SUBST_STAGE.paths=	pre-build
SUBST_FILES.paths=	${SCRIPTS_DIR}/rabbitmqctl ${SCRIPTS_DIR}/rabbitmq-env
SUBST_FILES.paths+=	${SCRIPTS_DIR}/rabbitmq-plugins ${SCRIPTS_DIR}/rabbitmq-server
SUBST_FILES.paths+=	${SCRIPTS_DIR}/rabbitmq-defaults
SUBST_SED.paths=	-e 's|/etc/rabbitmq|${PKG_SYSCONFDIR}|g'
SUBST_SED.paths+=	-e 's|/var/lib|${VARBASE}/db|g'
SUBST_SED.paths+=	-e 's|/var/log|${VARBASE}/log|g'
SUBST_SED.paths+=	-e 's|erl|${PREFIX}/bin/erl|g'
SUBST_VARS.paths=	RABBITMQ_HOME

REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmqctl
REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmq-defaults
REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmq-env
REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmq-plugins
REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmq-server

MAKE_ENV+=		MANDIR="${PREFIX}/${PKGMANDIR}"
MAKE_ENV+=		RMQ_BINDIR="${PREFIX}/sbin"
MAKE_ENV+=		RMQ_LIBDIR="${PREFIX}/lib/erlang/lib"
MAKE_ENV+=		RSYNC="${PREFIX}/bin/rsync"
MAKE_ENV+=		VERSION="${PKGVERSION_NOREV}"

INSTALL_TARGET=		install-erlapp install-scripts install-bin install-man

post-install:
	${INSTALL_DATA} ${WRKSRC}/deps/rabbit/docs/rabbitmq.config.example		\
		${DESTDIR}${PREFIX}/share/examples/rabbitmq
	${INSTALL_DATA} ${FILESDIR}/rabbitmq-env.conf 				\
		${DESTDIR}${PREFIX}/share/examples/rabbitmq

.include "../../lang/erlang/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
