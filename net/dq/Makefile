# $NetBSD: Makefile,v 1.1 2022/01/27 15:31:09 schmonz Exp $

GITHUB_PROJECT=		dq
GITHUB_TAG=		20220101
DISTNAME=		${GITHUB_PROJECT}
PKGNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=janmojzis/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/janmojzis/dq/
COMMENT=		Recursive DNS/DNSCurve server
LICENSE=		public-domain

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

DJB_MAKE_TARGETS=	no
BUILD_TARGET=		compile

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	do-configure
SUBST_FILES.etc=	dq/dns_rcrw.c dq/dq.c man/dq.1
SUBST_SED.etc=		-e 's|/etc/dnsrewrite|${PKG_SYSCONFBASE}/dnsrewrite|g'
SUBST_MESSAGE.etc=	Fixing prefix.

EGDIR=			share/examples/${PKGBASE}
INSTALLATION_DIRS=	${EGDIR}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dqcache/servers

CONF_FILES+=		${PREFIX}/${EGDIR}/dnscurveroots.global \
			${PKG_SYSCONFDIR}/dqcache/servers/@

PKG_GROUPS+=		${DQCACHE_GROUP}
PKG_USERS+=		${DQCACHE_USER}:${DQCACHE_GROUP}
BUILD_DEFS+=		DQCACHE_GROUP DQCACHE_USER PKG_SYSCONFBASE

RCD_SCRIPTS=		dqcache
FILES_SUBST+=		DQCACHE_USER=${DQCACHE_USER:Q}
FILES_SUBST+=		PKGNAME=${PKGNAME:Q}

post-configure:
	${RUN}cd ${DJB_CONFIG_DIR}; \
	[ -f conf-sbin ] && ${ECHO} ${DJB_CONFIG_PREFIX}/sbin > conf-sbin

post-install:
	for i in examples.md dnscurveroots.global; do \
		${INSTALL_DATA} ${FILESDIR}/$$i ${DESTDIR}${PREFIX}/${EGDIR}/; \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
