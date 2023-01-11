# $NetBSD: Makefile,v 1.98 2023/01/11 22:07:46 nikita Exp $

DISTNAME=	ejabberd-22.05
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	https://www.process-one.net/downloads/downloads-action.php?file=/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ejabberd.im/
COMMENT=	Free and Open Source distributed fault-tolerant Jabber server
LICENSE=	gnu-gpl-v2

DEPENDS+=	elixir>=1.4.4:../../lang/elixir
DEPENDS+=	erlang-base64url>=1.0.1:../../devel/erlang-base64url
DEPENDS+=	erlang-cache_tab>=1.0.30:../../devel/erlang-cache_tab
DEPENDS+=	erlang-epam>=1.0.12:../../security/erlang-epam
DEPENDS+=	erlang-eredis>=1.2.0:../../databases/erlang-eredis
DEPENDS+=	erlang-eimp>=1.0.22:../../graphics/erlang-eimp
DEPENDS+=	erlang-esip>=1.0.47:../../net/erlang-esip
DEPENDS+=	erlang-ezlib>=1.0.12:../../devel/erlang-ezlib
DEPENDS+=	erlang-fast_tls>=1.1.15:../../security/erlang-fast_tls
DEPENDS+=	erlang-fast_xml>=1.1.49:../../textproc/erlang-fast_xml
DEPENDS+=	erlang-fast_yaml>=1.0.33:../../textproc/erlang-fast_yaml
DEPENDS+=	erlang-idna>=6.0.0:../../net/erlang-idna
DEPENDS+=	erlang-jiffy>=1.1.1:../../textproc/erlang-jiffy
DEPENDS+=	erlang-jose>=1.11.1:../../security/erlang-jose
DEPENDS+=	erlang-lager>=3.9.1.:../../sysutils/erlang-lager
DEPENDS+=	erlang-luerl>=1.0:../../lang/erlang-luerl
DEPENDS+=	erlang-mqtree>=1.0.15:../../devel/erlang-mqtree
DEPENDS+=	erlang-p1_acme>=1.0.19:../../security/erlang-p1_acme
DEPENDS+=	erlang-p1_mysql>=1.0.19:../../databases/erlang-p1_mysql
DEPENDS+=	erlang-p1_oauth2>=0.6.11:../../security/erlang-p1_oauth2
DEPENDS+=	erlang-p1_pgsql>=1.1.18:../../databases/erlang-p1_pgsql
DEPENDS+=	erlang-p1_utils>=1.0.25:../../misc/erlang-p1_utils
DEPENDS+=	erlang-pkix>=1.0.9:../../security/erlang-pkix
DEPENDS+=	erlang-sqlite3>=1.1.13:../../databases/erlang-sqlite3
DEPENDS+=	erlang-stringprep>=1.0.28:../../textproc/erlang-stringprep
DEPENDS+=	erlang-stun>=1.2.2:../../net/erlang-stun
DEPENDS+=	erlang-xmpp>=1.5.8:../../net/erlang-xmpp
DEPENDS+=	erlang-yconf>=1.0.13:../../textproc/erlang-yconf

GNU_CONFIGURE=		yes
USE_GCC_RUNTIME=	yes
USE_TOOLS+=		aclocal autoconf automake bash:run gmake patch perl

CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--enable-system-deps
CONFIGURE_ARGS+=	--enable-erlang-version-check=no
CONFIGURE_ARGS+=	--enable-mysql
CONFIGURE_ARGS+=	--enable-odbc
CONFIGURE_ARGS+=	--enable-pam
CONFIGURE_ARGS+=	--enable-pgsql
CONFIGURE_ARGS+=	--enable-redis
CONFIGURE_ARGS+=	--enable-sip
CONFIGURE_ARGS+=	--enable-stun
CONFIGURE_ARGS+=	--enable-zlib
CONFIGURE_ARGS+=	--enable-user=${EJABBERD_USER}
CONFIGURE_ARGS+=	--enable-group=${EJABBERD_GROUP}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

MAKE_ENV+=		USE_GLOBAL_DEPS=true

RCD_SCRIPTS=		ejabberd

BUILD_DEFS+=		EJABBERD_USER EJABBERD_GROUP EJABBERD_LOGDIR
BUILD_DEFS+=		EJABBERD_PIDDIR EJABBERD_DB EJABBERD_TRANSDIR
BUILD_DEFS+=		VARBASE
PKG_SYSCONFSUBDIR=	ejabberd

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

EJABBERD_USER?=		ejabberd
EJABBERD_GROUP?=	ejabberd
EJABBERD_PIDDIR?=	${VARBASE}/run/ejabberd
EJABBERD_LOGDIR?=	${VARBASE}/log/ejabberd
EJABBERD_DB?=		${VARBASE}/spool/ejabberd

OWN_DIRS_PERMS+=	${EJABBERD_PIDDIR} ${EJABBERD_USER} ${EJABBERD_GROUP} 0770
OWN_DIRS_PERMS+=	${EJABBERD_LOGDIR} ${EJABBERD_USER} ${EJABBERD_GROUP} 0770
OWN_DIRS_PERMS+=	${EJABBERD_DB} ${EJABBERD_USER} ${EJABBERD_GROUP} 0770

FILES_SUBST+=		EJABBERD_USER=${EJABBERD_USER}
FILES_SUBST+=		EJABBERD_GROUP=${EJABBERD_GROUP}
FILES_SUBST+=		EJABBERD_DB=${EJABBERD_DB}

PKG_GROUPS+=			${EJABBERD_GROUP}
PKG_USERS+=			${EJABBERD_USER}:${EJABBERD_GROUP}
PKG_GECOS.${EJABBERD_USER}=	ejabberd user
PKG_HOME.${EJABBERD_USER}=	${EJABBERD_DB}
PKG_SHELL.${EJABBERD_USER}=	${SH}

EGDIR=			share/examples/ejabberd

INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/doc/${PKGBASE} ${EGDIR}
INSTALLATION_DIRS+=	lib/${DISTNAME}/priv/sql

CONF_FILES_PERMS=	${EGDIR}/ejabberd.yml ${PKG_SYSCONFDIR}/ejabberd.yml \
			${REAL_ROOT_USER} ${EJABBERD_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/ejabberdctl.cfg ${PKG_SYSCONFDIR}/ejabberdctl.cfg \
			${REAL_ROOT_USER} ${EJABBERD_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/inetrc ${PKG_SYSCONFDIR}/inetrc \
			${REAL_ROOT_USER} ${EJABBERD_GROUP} 0640
SPECIAL_PERMS+=		sbin/ejabberdctl ${REAL_ROOT_USER} ${EJABBERD_GROUP} 0750

REPLACE_BASH=		ejabberdctl.template tools/captcha.sh

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Localizing paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile.in
SUBST_VARS.paths=	DISTNAME EJABBERD_DB EJABBERD_LOGDIR EJABBERD_PIDDIR
SUBST_VARS.paths+=	PKG_SYSCONFDIR PREFIX LOCALBASE

post-extract:
	cd ${WRKSRC} && ${MKDIR} deps && ${TOUCH} deps/.got deps/.built

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/tools/ejabberdctl.bc			\
		${DESTDIR}${PREFIX}/share/bash-completion/completions/ejabberd
	cd ${WRKSRC}/sql && ${INSTALL_DATA} *.sql			\
		${DESTDIR}${PREFIX}/lib/${PKGNAME_NOREV}/priv/sql

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
