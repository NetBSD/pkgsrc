# $NetBSD: Makefile,v 1.63 2016/01/18 10:23:18 fhajny Exp $

DISTNAME=	ejabberd-16.01
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://www.process-one.net/downloads/ejabberd/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.ejabberd.im/
COMMENT=	Free and Open Source distributed fault-tolerant Jabber server
LICENSE=	gnu-gpl-v2

DEPENDS+=	erlang-cache_tab>=1.0.1:../../devel/erlang-p1_cache_tab
DEPENDS+=	erlang-goldrush-0.1.*:../../sysutils/erlang-goldrush
DEPENDS+=	erlang-jiffy>=0.14.5:../../textproc/erlang-jiffy
DEPENDS+=	erlang-lager>=3.0.2:../../sysutils/erlang-lager
DEPENDS+=	erlang-oauth2>=0.6.0.20150911:../../security/erlang-oauth2
DEPENDS+=	erlang-p1_iconv-0.9.*:../../converters/erlang-p1_iconv
DEPENDS+=	erlang-p1_mysql>=1.0.0:../../databases/erlang-p1_mysql
DEPENDS+=	erlang-p1_pam>=1.0.0:../../security/erlang-p1_pam
DEPENDS+=	erlang-p1_pgsql>=1.0.0:../../databases/erlang-p1_pgsql
DEPENDS+=	erlang-p1_sip>=1.0.0:../../net/erlang-p1_sip
DEPENDS+=	erlang-p1_stringprep>=1.0.0:../../textproc/erlang-p1_stringprep
DEPENDS+=	erlang-p1_stun-0.9.*:../../net/erlang-p1_stun
DEPENDS+=	erlang-p1_tls>=1.0.0:../../security/erlang-p1_tls
DEPENDS+=	erlang-p1_utils>=1.0.2:../../misc/erlang-p1_utils
DEPENDS+=	erlang-p1_xml>=1.1.1:../../textproc/erlang-p1_xml
DEPENDS+=	erlang-p1_yaml>=1.0.0:../../textproc/erlang-p1_yaml
DEPENDS+=	erlang-p1_zlib>=1.0.0:../../devel/erlang-p1_zlib
DEPENDS+=	erlang-xmlrpc>=1.15.20150506:../../textproc/erlang-xmlrpc
CONFLICTS+=	jabberd-[0-9]*

GNU_CONFIGURE=		yes
USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash:run gmake patch

CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--enable-iconv
CONFIGURE_ARGS+=	--enable-lager
CONFIGURE_ARGS+=	--enable-mysql
CONFIGURE_ARGS+=	--enable-odbc
CONFIGURE_ARGS+=	--enable-pam
CONFIGURE_ARGS+=	--enable-pgsql
CONFIGURE_ARGS+=	--enable-zlib
CONFIGURE_ARGS+=	--enable-user=${EJABBERD_USER}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

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

PKG_GROUPS+=		${EJABBERD_GROUP}
PKG_USERS+=		${EJABBERD_USER}:${EJABBERD_GROUP}
PKG_GECOS.${EJABBERD_USER}=	ejabberd user
PKG_HOME.${EJABBERD_USER}=	${EJABBERD_DB}
PKG_SHELL.${EJABBERD_USER}=	${SH}

EGDIR=			share/examples/ejabberd

INSTALLATION_DIRS+=	share/doc/${PKGBASE} ${EGDIR} share/bash-completion.d
INSTALLATION_DIRS+=	lib/erlang/lib/${DISTNAME}/priv/sql

CONF_FILES_PERMS=	${EGDIR}/ejabberd.yml ${PKG_SYSCONFDIR}/ejabberd.yml \
			${ROOT_USER} ${EJABBERD_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/ejabberdctl.cfg ${PKG_SYSCONFDIR}/ejabberdctl.cfg \
			${ROOT_USER} ${EJABBERD_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/inetrc ${PKG_SYSCONFDIR}/inetrc \
			${ROOT_USER} ${EJABBERD_GROUP} 0640
SPECIAL_PERMS+=		sbin/ejabberdctl ${ROOT_USER} ${EJABBERD_GROUP} 0750

REPLACE_BASH=		ejabberdctl.template tools/captcha.sh

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Localizing paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile.in ejabberd.yml.example ejabberdctl.template
SUBST_FILES.paths+=	tools/ejabberdctl.bc
SUBST_VARS.paths=	DISTNAME EJABBERD_DB EJABBERD_LOGDIR EJABBERD_PIDDIR
SUBST_VARS.paths+=	PKG_SYSCONFDIR PREFIX

post-extract:
	cd ${WRKSRC} && ${MKDIR} deps && ${TOUCH} deps/.got deps/.built

post-install:
	${INSTALL_DATA} ${WRKSRC}/tools/ejabberdctl.bc			\
		${DESTDIR}${PREFIX}/share/bash-completion.d/ejabberd
	cd ${WRKSRC}/sql && ${INSTALL_DATA} *.sql			\
		${DESTDIR}${PREFIX}/lib/erlang/lib/${DISTNAME}/priv/sql

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
