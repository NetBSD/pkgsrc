# $NetBSD: Makefile,v 1.20 2020/04/12 08:28:21 adam Exp $

DISTNAME=	inspircd-3.5.0
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=inspircd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.inspircd.org/
COMMENT=	Modular Internet Relay Chat (IRC) server (v3 branch)
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake perl pkg-config
USE_LANGUAGES=	c99 gnu++03
HAS_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile
MAKE_ENV+=	INSTALL=${INSTALL:Q}

BUILD_DEFS+=	PKG_SYSCONFDIR

PKG_SYSCONFSUBDIR=	inspircd

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--example-dir=${EGDIR}
CONFIGURE_ARGS+=	--manual-dir=${PREFIX}/${PKGMANDIR}/man1
CONFIGURE_ARGS+=	--module-dir=${PREFIX}/lib/inspircd/modules
CONFIGURE_ARGS+=	--config-dir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--data-dir=${PREFIX}/inspircd/data
CONFIGURE_ARGS+=	--log-dir=${PREFIX}/inspircd/logs
CONFIGURE_ARGS+=	--script-dir=${PREFIX}/inspircd/scripts
CONFIGURE_ARGS+=	--disable-auto-extras
CONFIGURE_ARGS+=	--distribution-label=pkgsrc

CONFIG_SHELL=		${PERL5}

REPLACE_PERL+=		tools/genssl

.include "../../mk/bsd.prefs.mk"

INSPIRCD_USER?=		inspircd
INSPIRCD_GROUP?=	inspircd
PKG_GROUPS=		${INSPIRCD_GROUP}
PKG_USERS=		${INSPIRCD_USER}:${INSPIRCD_GROUP}
PKG_GROUPS_VARS=	INSPIRCD_USER
PKG_USERS_VARS=		INSPIRCD_GROUP

FILES_SUBST+=		INSPIRCD_GROUP=${INSPIRCD_GROUP:Q}
FILES_SUBST+=		INSPIRCD_USER=${INSPIRCD_USER:Q}

EGDIR=			${PREFIX}/share/examples/inspircd

CONF_FILES_PERMS+=	${EGDIR}/inspircd.conf.example ${PKG_SYSCONFDIR}/inspircd.conf \
			${INSPIRCD_USER} ${INSPIRCD_GROUP} 0600
CONF_FILES_PERMS+=	${EGDIR}/links.conf.example ${PKG_SYSCONFDIR}/links.conf \
			${INSPIRCD_USER} ${INSPIRCD_GROUP} 0600
CONF_FILES_PERMS+=	${EGDIR}/modules.conf.example ${PKG_SYSCONFDIR}/modules.conf \
			${INSPIRCD_USER} ${INSPIRCD_GROUP} 0600
CONF_FILES_PERMS+=	${EGDIR}/opers.conf.example ${PKG_SYSCONFDIR}/opers.conf \
			${INSPIRCD_USER} ${INSPIRCD_GROUP} 0600
CONF_FILES_PERMS+=	${EGDIR}/filter.conf.example ${PKG_SYSCONFDIR}/filter.conf \
			${INSPIRCD_USER} ${INSPIRCD_GROUP} 0600
CONF_FILES_PERMS+=	${EGDIR}/helpop.conf.example ${PKG_SYSCONFDIR}/helpop.conf \
			${INSPIRCD_USER} ${INSPIRCD_GROUP} 0600
CONF_FILES_PERMS+=	${EGDIR}/motd.txt.example ${PKG_SYSCONFDIR}/motd.txt \
			${INSPIRCD_USER} ${INSPIRCD_GROUP} 0644
CONF_FILES_PERMS+=	${EGDIR}/opermotd.txt.example ${PKG_SYSCONFDIR}/opermotd.txt \
			${INSPIRCD_USER} ${INSPIRCD_GROUP} 0600
CONF_FILES_PERMS+=	${EGDIR}/quotes.txt.example ${PKG_SYSCONFDIR}/quotes.txt \
			${INSPIRCD_USER} ${INSPIRCD_GROUP} 0644
CONF_FILES_PERMS+=	${EGDIR}/services/anope.conf.example ${PKG_SYSCONFDIR}/services/anope.conf \
			${INSPIRCD_USER} ${INSPIRCD_GROUP} 0600
CONF_FILES_PERMS+=	${EGDIR}/services/atheme.conf.example ${PKG_SYSCONFDIR}/services/atheme.conf \
			${INSPIRCD_USER} ${INSPIRCD_GROUP} 0600
CONF_FILES_PERMS+=	${EGDIR}/services/generic.conf.example ${PKG_SYSCONFDIR}/services/generic.conf \
			${INSPIRCD_USER} ${INSPIRCD_GROUP} 0600

OWN_DIRS_PERMS+=	${PREFIX}/inspircd ${INSPIRCD_USER} ${INSPIRCD_GROUP} 0755
OWN_DIRS_PERMS+=	${PREFIX}/inspircd/data ${INSPIRCD_USER} ${INSPIRCD_GROUP} 0755
OWN_DIRS_PERMS+=	${PREFIX}/inspircd/logs ${INSPIRCD_USER} ${INSPIRCD_GROUP} 0755
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR} ${INSPIRCD_USER} ${INSPIRCD_GROUP} 0755
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/services ${INSPIRCD_USER} ${INSPIRCD_GROUP} 0755

RCD_SCRIPTS=		inspircd

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Set variables in configuration file.
SUBST_FILES.conf+=	docs/conf/inspircd.conf.example
SUBST_VARS.conf+=	PREFIX

INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${EGDIR}/sql
INSTALLATION_DIRS+=	${EGDIR}/services

INSPIRCD_EXTRAS+=	m_regex_posix.cpp

.include "options.mk"

.if !empty(PKG_OPTIONS:Mopenssl) || !empty(PKG_OPTIONS:Mgnutls) || \
    !empty(PKG_OPTIONS:Mmbedtls)
INSPIRCD_EXTRAS+=	m_sslrehashsignal.cpp
.endif

post-configure:
	cd ${WRKSRC} && ${CONFIGURE_ENV} ${PERL5} ./configure \
	    --enable-extras=${INSPIRCD_EXTRAS:ts,}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
