# $NetBSD: Makefile,v 1.2 2019/05/03 19:03:02 nia Exp $

DISTNAME=	inspircd-3.0.0
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=inspircd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.inspircd.org/
COMMENT=	Modular Internet Relay Chat (IRC) server
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake perl pkg-config
USE_LANGUAGES=	c c++11
HAS_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

BUILD_DEFS+=	PKG_SYSCONFDIR

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--manual-dir=${PREFIX}/${PKGMANDIR}/man1
CONFIGURE_ARGS+=	--module-dir=${PREFIX}/lib/inspircd/modules
CONFIGURE_ARGS+=	--config-dir=${PKG_SYSCONFDIR}/inspircd
CONFIGURE_ARGS+=	--data-dir=${PREFIX}/inspircd/data
CONFIGURE_ARGS+=	--log-dir=${PREFIX}/inspircd/logs
CONFIG_SHELL=		${PERL5}

REPLACE_PERL+=		tools/genssl

.include "../../mk/bsd.prefs.mk"

CONF_FILES+=	${EGDIR}/motd.txt.example ${PKG_SYSCONFDIR}/inspircd/motd.txt
CONF_FILES+=	${EGDIR}/inspircd.conf.example ${PKG_SYSCONFDIR}/inspircd/inspircd.conf
CONF_FILES+=	${EGDIR}/links.conf.example ${PKG_SYSCONFDIR}/inspircd/links.conf
CONF_FILES+=	${EGDIR}/modules.conf.example ${PKG_SYSCONFDIR}/inspircd/modules.conf
CONF_FILES+=	${EGDIR}/opers.conf.example ${PKG_SYSCONFDIR}/inspircd/opers.conf
CONF_FILES+=	${EGDIR}/motd.txt.example ${PKG_SYSCONFDIR}/inspircd/motd.txt

CONF_FILES+=	${EGDIR}/filter.conf.example ${PKG_SYSCONFDIR}/inspircd/filter.conf
CONF_FILES+=	${EGDIR}/helpop.conf.example ${PKG_SYSCONFDIR}/inspircd/helpop.conf
CONF_FILES+=	${EGDIR}/inspircd.conf.example ${PKG_SYSCONFDIR}/inspircd/inspircd.conf
CONF_FILES+=	${EGDIR}/links.conf.example ${PKG_SYSCONFDIR}/inspircd/links.conf
CONF_FILES+=	${EGDIR}/modules.conf.example ${PKG_SYSCONFDIR}/inspircd/modules.conf
CONF_FILES+=	${EGDIR}/motd.txt.example ${PKG_SYSCONFDIR}/inspircd/motd.txt
CONF_FILES+=	${EGDIR}/opermotd.txt.example ${PKG_SYSCONFDIR}/inspircd/opermotd.txt
CONF_FILES+=	${EGDIR}/opers.conf.example ${PKG_SYSCONFDIR}/inspircd/opers.conf
CONF_FILES+=	${EGDIR}/quotes.txt.example ${PKG_SYSCONFDIR}/inspircd/quotes.txt
CONF_FILES+=	${EGDIR}/services/anope.conf.example ${PKG_SYSCONFDIR}/inspircd/services/anope.conf
CONF_FILES+=	${EGDIR}/services/atheme.conf.example ${PKG_SYSCONFDIR}/inspircd/services/atheme.conf
CONF_FILES+=	${EGDIR}/services/generic.conf.example ${PKG_SYSCONFDIR}/inspircd/services/generic.conf

INSPIRCD_USER?=		inspircd
INSPIRCD_GROUP?=	inspircd
PKG_GROUPS=		${INSPIRCD_GROUP}
PKG_USERS=		${INSPIRCD_USER}:${INSPIRCD_GROUP}
PKG_GROUPS_VARS=	INSPIRCD_USER
PKG_USERS_VARS=		INSPIRCD_GROUP

FILES_SUBST+=		INSPIRCD_GROUP=${INSPIRCD_GROUP:Q}
FILES_SUBST+=		INSPIRCD_USER=${INSPIRCD_USER:Q}

OWN_DIRS_PERMS+=	${PREFIX}/inspircd ${INSPIRCD_USER} ${INSPIRCD_GROUP} 0755
OWN_DIRS_PERMS+=	${PREFIX}/inspircd/data ${INSPIRCD_USER} ${INSPIRCD_GROUP} 0755
OWN_DIRS_PERMS+=	${PREFIX}/inspircd/logs ${INSPIRCD_USER} ${INSPIRCD_GROUP} 0755

RCD_SCRIPTS=		inspircd

EGDIR=			${PREFIX}/share/examples/inspircd

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Set variables in configuration file.
SUBST_FILES.conf+=	docs/conf/inspircd.conf.example
SUBST_VARS.conf+=	PREFIX

INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${EGDIR}/sql
INSTALLATION_DIRS+=	${EGDIR}/services
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/inspircd/services

INSPIRCD_EXTRAS_OFF+=	m_regex_re2.cpp
INSPIRCD_EXTRAS_OFF+=	m_regex_tre.cpp

CONFIGURE_ARGS+=	--distribution-label=pkgsrc

# https://github.com/inspircd/inspircd/commit/044fa999680888267e07dc7b69028b18efbac818
# this has no side-effects other than allowing the build to proceed with
# distribution-label set
CONFIGURE_ARGS+=	--development

.include "options.mk"

post-configure:
	cd ${WRKSRC} && ${CONFIGURE_ENV} ${PERL5} ./configure \
	    --enable-extras=${INSPIRCD_EXTRAS_ON:C/\.cpp[ ]* m_/.cpp,m_/gW} \
	    --disable-extras=${INSPIRCD_EXTRAS_OFF:C/\.cpp[ ]* m_/.cpp,m_/gW}

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/inspircd/examples/* \
	    ${DESTDIR}${PREFIX}/share/examples/inspircd
	${RM} -rf ${DESTDIR}${PREFIX}/etc/inspircd/examples
	${RM} -f ${DESTDIR}${PREFIX}/.gdbargs
	${CHMOD} ${BINMODE} ${DESTDIR}${PREFIX}/bin/inspircd
	${CHMOD} ${BINMODE} ${DESTDIR}${PREFIX}/bin/inspircd-genssl
	${CHMOD} ${BINMODE} ${DESTDIR}${PREFIX}/lib/inspircd/modules/*.so

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
