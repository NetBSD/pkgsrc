# $NetBSD: Makefile,v 1.88 2020/05/27 19:37:37 wiz Exp $

DISTNAME=	ejabberd-18.06
CATEGORIES=	chat
MASTER_SITES=	https://www.process-one.net/downloads/ejabberd/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ejabberd.im/
COMMENT=	Free and Open Source distributed fault-tolerant Jabber server
LICENSE=	gnu-gpl-v2

DEPENDS+=	erlang-cache_tab>=1.0.14:../../devel/erlang-cache_tab
DEPENDS+=	erlang-epam>=1.0.4:../../security/erlang-epam
DEPENDS+=	erlang-eredis>=1.0.8.20150910:../../databases/erlang-eredis
DEPENDS+=	erlang-eimp>=1.0.6:../../graphics/erlang-eimp
DEPENDS+=	erlang-esip>=1.0.24:../../net/erlang-esip
DEPENDS+=	erlang-ezlib>=1.0.4:../../devel/erlang-ezlib
DEPENDS+=	erlang-fast_tls>=1.0.23:../../security/erlang-fast_tls
DEPENDS+=	erlang-fast_xml>=1.1.31:../../textproc/erlang-fast_xml
DEPENDS+=	erlang-fast_yaml>=1.0.15:../../textproc/erlang-fast_yaml
DEPENDS+=	erlang-iconv>=1.0.8:../../converters/erlang-iconv
DEPENDS+=	erlang-jiffy>=0.14.8:../../textproc/erlang-jiffy
DEPENDS+=	erlang-jose>=1.8.4:../../security/erlang-jose
DEPENDS+=	erlang-lager>=3.4.2.:../../sysutils/erlang-lager
DEPENDS+=	erlang-luerl>=0.3:../../lang/erlang-luerl
DEPENDS+=	erlang-p1_mysql>=1.0.6:../../databases/erlang-p1_mysql
DEPENDS+=	erlang-p1_oauth2>=0.6.3:../../security/erlang-p1_oauth2
DEPENDS+=	erlang-p1_pgsql>=1.1.6:../../databases/erlang-p1_pgsql
DEPENDS+=	erlang-p1_utils>=1.0.12:../../misc/erlang-p1_utils
DEPENDS+=	erlang-stringprep>=1.0.12:../../textproc/erlang-stringprep
DEPENDS+=	erlang-stun>=1.0.23:../../net/erlang-stun
DEPENDS+=	erlang-xmpp>=1.2.1:../../net/erlang-xmpp

GNU_CONFIGURE=		yes
USE_GCC_RUNTIME=	yes
USE_TOOLS+=		bash:run gmake patch

CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--enable-system-deps
CONFIGURE_ARGS+=	--enable-iconv
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

INSTALLATION_DIRS+=	share/doc/${PKGBASE} ${EGDIR} share/bash-completion.d
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
SUBST_FILES.paths=	Makefile.in ejabberd.yml.example ejabberdctl.template
SUBST_FILES.paths+=	tools/ejabberdctl.bc
SUBST_VARS.paths=	DISTNAME EJABBERD_DB EJABBERD_LOGDIR EJABBERD_PIDDIR
SUBST_VARS.paths+=	PKG_SYSCONFDIR PREFIX LOCALBASE

post-extract:
	cd ${WRKSRC} && ${MKDIR} deps && ${TOUCH} deps/.got deps/.built

post-install:
	${INSTALL_DATA} ${WRKSRC}/tools/ejabberdctl.bc			\
		${DESTDIR}${PREFIX}/share/bash-completion.d/ejabberd
	cd ${WRKSRC}/sql && ${INSTALL_DATA} *.sql			\
		${DESTDIR}${PREFIX}/lib/${PKGNAME_NOREV}/priv/sql

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
