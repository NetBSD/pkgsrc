# $NetBSD: Makefile,v 1.114 2026/02/15 18:22:30 gdt Exp $

DISTNAME=	ejabberd-26.01
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.ejabberd.im/
COMMENT=	Free and Open Source distributed fault-tolerant Jabber server
LICENSE=	gnu-gpl-v2

# As of 2025-04, no one responded to a query on pkgsrc-users@ asking
# if anyone else used ejabberd.  Thus, gdt intends to commit updates
# if they test ok on his server, and not worry about other usages.
# Feel free to speak up!

GNU_CONFIGURE=		yes
USE_GCC_RUNTIME=	yes
USE_TOOLS+=		aclocal autoconf automake bash:run gmake patch perl

# Upstream allows building with mix, rebar(2), and rebar3.  As of
# 22.05, the mix build fails, and both rebar versions work.  Disabling
# bundled deps seems cleaner with rebar(2).
# In general the erlang ecosystem is troubled by language-specific
# packaging disease, but this isn't particularly about ejabberd.
# Useful info at https://github.com/processone/ejabberd/issues/4431

#Tries to download, objecting to p1_utils
#TOOL_DEPENDS+=		elixir-[0-9]*:../../lang/elixir

# Works.
TOOL_DEPENDS+=		rebar>=2:../../devel/rebar
CONFIGURE_ARGS+=	--with-rebar=rebar

# Fetches dependencies even though they are present.
#TOOL_DEPENDS+=		rebar3>=3:../../devel/rebar3
#CONFIGURE_ARGS+=	--with-rebar=rebar3
# Throws an error on the forced bad proxy, but with
# https://127.0.0.1:65535/ errors on not being able to update
# rebar3_hexpm.
#ALLOW_NETWORK_ACCESS=	yes

# We intend to use the erlang packages DEPENDed on below, rather than
# having ejabberd's build system download and build them.  The
# configure option seems to work for rebar(2), but not for mix or
# rebar3.
CONFIGURE_ARGS+=	--enable-system-deps

CONFIGURE_ARGS+=	--disable-debug			# debug is default on (a clue?)
CONFIGURE_ARGS+=	--enable-mysql
CONFIGURE_ARGS+=	--enable-odbc
CONFIGURE_ARGS+=	--enable-pam
CONFIGURE_ARGS+=	--enable-pgsql
CONFIGURE_ARGS+=	--enable-sip
CONFIGURE_ARGS+=	--enable-stun
CONFIGURE_ARGS+=	--enable-zlib
CONFIGURE_ARGS+=	--enable-user=${EJABBERD_USER}
CONFIGURE_ARGS+=	--enable-group=${EJABBERD_GROUP}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

# Dependencies from rebar.config
# (We assume erlang >= 27; it is too painful to accomodate old erlang.)
BUILDLINK_API_DEPENDS.erlang+=	erlang>=27.0

DEPENDS+=	erlang-cache_tab>=1.0.33:../../devel/erlang-cache_tab
DEPENDS+=	erlang-eimp>=1.0.26:../../graphics/erlang-eimp
DEPENDS+=	erlang-epam>=1.0.14:../../security/erlang-epam
# pkgsrc eredis is too old, so no redis for now
#DEPENDS+=	erlang-eredis>=1.7.1:../../databases/erlang-eredis
DEPENDS+=	erlang-erlydtl>=0.15.0:../../textproc/erlang-erlydtl
DEPENDS+=	erlang-esip>=1.0.59:../../net/erlang-esip
DEPENDS+=	erlang-ezlib>=1.0.15:../../devel/erlang-ezlib
DEPENDS+=	erlang-fast_tls>=1.1.25:../../security/erlang-fast_tls
DEPENDS+=	erlang-fast_xml>=1.1.57:../../textproc/erlang-fast_xml
DEPENDS+=	erlang-fast_yaml>=1.0.39:../../textproc/erlang-fast_yaml
DEPENDS+=	erlang-idna>=6.0.0:../../net/erlang-idna
# <27: jiffy (skipped)
DEPENDS+=	erlang-jose>=1.11.12:../../security/erlang-jose
# --enable-lua, default off (used for importing from prosody)
#DEPENDS+=	erlang-luerl>=1.2.0:../../lang/erlang-luerl
DEPENDS+=	erlang-mqtree>=1.0.19:../../devel/erlang-mqtree
DEPENDS+=	erlang-p1_acme>=1.0.30:../../security/erlang-p1_acme
DEPENDS+=	erlang-p1_mysql>=1.0.27:../../databases/erlang-p1_mysql
DEPENDS+=	erlang-p1_oauth2>=0.6.14:../../security/erlang-p1_oauth2
DEPENDS+=	erlang-p1_pgsql>=1.1.38:../../databases/erlang-p1_pgsql
DEPENDS+=	erlang-p1_utils>=1.0.28:../../misc/erlang-p1_utils
DEPENDS+=	erlang-pkix>=1.0.10:../../security/erlang-pkix
DEPENDS+=	erlang-stringprep>=1.0.33:../../textproc/erlang-stringprep
DEPENDS+=	erlang-stun>=1.2.21:../../net/erlang-stun
DEPENDS+=	erlang-xmpp>=1.12.0:../../net/erlang-xmpp
DEPENDS+=	erlang-yconf>=1.0.22:../../textproc/erlang-yconf

RCD_SCRIPTS=		ejabberd

BUILD_DEFS+=		EJABBERD_USER EJABBERD_GROUP EJABBERD_LOGDIR
BUILD_DEFS+=		EJABBERD_PIDDIR EJABBERD_DB
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
	# Upstream includes rebar(2) and rebar3 built with a
	# particular OTP.  Remove both and symlink in the one we are
	# using -- built with the current OTP.  (This appears not to
	# be necessary with ejabberd 25.04 and erlang 27, but has been
	# needed in the past.)
	cd ${WRKSRC} && ${RM} rebar rebar3 && ${LN} -s ${LOCALBASE}/bin/rebar .
	# Building deps is disabled above; this is leftover code to
	# disable them differently.  It is intentionally left
	# commented out because it may be necessary with rebar3, which may be
	# necessary in future ejabberd.
	#cd ${WRKSRC} && ${MKDIR} deps && ${TOUCH} deps/.got deps/.built

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/tools/ejabberdctl.bc			\
		${DESTDIR}${PREFIX}/share/bash-completion/completions/ejabberd
	cd ${WRKSRC}/sql && ${INSTALL_DATA} *.sql			\
		${DESTDIR}${PREFIX}/lib/${PKGNAME_NOREV}/priv/sql

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
