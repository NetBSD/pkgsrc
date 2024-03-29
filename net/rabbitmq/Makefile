# $NetBSD: Makefile,v 1.93 2024/02/22 22:56:08 adam Exp $

DISTNAME=	rabbitmq-server-3.12.13
PKGNAME=	${DISTNAME:S/-server//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=rabbitmq/}
EXTRACT_SUFX=	.tar.xz
GITHUB_PROJECT=	rabbitmq-server
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.rabbitmq.com/
COMMENT=	Implementation of AMQP that provides robust messaging for applications
LICENSE=	mpl-1.1

USE_TOOLS+=		bash:run gmake unzip zip

TOOL_DEPENDS+=		elixir-[0-9]*:../../lang/elixir
TOOL_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=		rsync-[0-9]*:../../net/rsync
TOOL_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto
DEPENDS+=		${PYPKGPREFIX}-simplejson>=2:../../converters/py-simplejson

BUILD_DEFS+=		VARBASE

# Create a mix tool to avoid nested interpreter issues.
TOOLS_CREATE+=		mix
TOOLS_SCRIPT.mix=	${PREFIX}/bin/elixir -r ${PREFIX}/bin/mix -- "$$@"

.include "../../mk/bsd.prefs.mk"

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
CONF_FILES+=		share/examples/rabbitmq/rabbitmq.conf.example \
			${PKG_SYSCONFDIR}/rabbitmq.conf

FILES_SUBST+=		RMQ_USER=${RMQ_USER}
FILES_SUBST+=		RMQ_GROUP=${RMQ_GROUP}
FILES_SUBST+=		RMQ_DIR=${RMQ_DIR}

RABBITMQ_HOME=		lib/erlang/lib/rabbitmq_server-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	share/examples/rabbitmq

SCRIPTS_DIR=		${WRKSRC}/deps/rabbit/scripts

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting standard paths
SUBST_STAGE.paths=	pre-build
SUBST_FILES.paths=	${SCRIPTS_DIR}/rabbitmq-env
SUBST_FILES.paths+=	${SCRIPTS_DIR}/rabbitmq-server
SUBST_FILES.paths+=	${SCRIPTS_DIR}/rabbitmq-defaults
SUBST_SED.paths=	-e 's|/etc/rabbitmq|${PKG_SYSCONFDIR}|g'
SUBST_SED.paths+=	-e 's|/var/lib|${VARBASE}/db|g'
SUBST_SED.paths+=	-e 's|/var/log|${VARBASE}/log|g'
SUBST_SED.paths+=	-e 's|exec erl|exec ${PREFIX}/bin/erl|g'
SUBST_SED.paths+=	-e 's|@RABBITMQ_HOME@|${PREFIX}/${RABBITMQ_HOME}|g'

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Setting prefix path
SUBST_STAGE.prefix=	pre-build
SUBST_FILES.prefix=	deps/rabbit_common/src/rabbit_env.erl
SUBST_VARS.prefix=	PREFIX

REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmqctl
REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmq-defaults
REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmq-env
REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmq-plugins
REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmq-queues
REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmq-server
REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmq-streams
REPLACE_BASH+=		${SCRIPTS_DIR}/rabbitmq-upgrade

CHECK_PORTABILITY_SKIP+=	scripts/rabbitmq-server-ha.ocf

# Too much effort to replace the shebang on generated files
CHECK_INTERPRETER_SKIP+=	${RABBITMQ_HOME}/escript/rabbitmq-diagnostics
CHECK_INTERPRETER_SKIP+=	${RABBITMQ_HOME}/escript/rabbitmq-plugins
CHECK_INTERPRETER_SKIP+=	${RABBITMQ_HOME}/escript/rabbitmq-queues
CHECK_INTERPRETER_SKIP+=	${RABBITMQ_HOME}/escript/rabbitmq-streams
CHECK_INTERPRETER_SKIP+=	${RABBITMQ_HOME}/escript/rabbitmq-tanzu
CHECK_INTERPRETER_SKIP+=	${RABBITMQ_HOME}/escript/rabbitmq-upgrade
CHECK_INTERPRETER_SKIP+=	${RABBITMQ_HOME}/escript/rabbitmqctl
CHECK_INTERPRETER_SKIP+=	${RABBITMQ_HOME}/escript/vmware-rabbitmq
CHECK_INTERPRETER_SKIP+=	${RABBITMQ_HOME}/sbin/cuttlefish

MAKE_ENV+=		MANDIR="${PREFIX}/${PKGMANDIR}"
MAKE_ENV+=		RMQ_BINDIR="${PREFIX}/sbin"
MAKE_ENV+=		RMQ_LIBDIR="${PREFIX}/lib/erlang/lib"
MAKE_ENV+=		RSYNC="${PREFIX}/bin/rsync"
MAKE_ENV+=		VERSION="${PKGVERSION_NOREV}"

INSTALL_TARGET=		install-erlapp install-scripts install-bin install-man
# XXX this test target doesn't work correctly at present, needs investigation.
TEST_TARGET=		check

post-install:
	${INSTALL_DATA} ${WRKSRC}/deps/rabbit/docs/rabbitmq.conf.example \
		${DESTDIR}${PREFIX}/share/examples/rabbitmq
	${INSTALL_DATA} ${FILESDIR}/rabbitmq-env.conf \
		${DESTDIR}${PREFIX}/share/examples/rabbitmq

.include "../../lang/erlang/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
