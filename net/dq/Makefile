# $NetBSD: Makefile,v 1.4 2023/01/10 17:09:08 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}
PKGNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=janmojzis/}
GITHUB_PROJECT=		dq
GITHUB_TAG=		20230101

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/janmojzis/dq/
COMMENT=		Recursive DNS/DNSCurve server
LICENSE=		cc0-1.0-universal

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	do-configure
SUBST_FILES.etc=	dns_rcrw.c dq.c man/dq.1
SUBST_SED.etc=		-e 's|/etc/dnsrewrite|${PKG_SYSCONFBASE}/dnsrewrite|g'

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	do-configure
SUBST_FILES.prefix=	Makefile
SUBST_VARS.prefix=	PREFIX

EGDIR=			share/examples/${PKGBASE}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dqcache/servers

CONF_FILES+=		${PREFIX}/${EGDIR}/dnscurveroots.global \
			${PKG_SYSCONFDIR}/dqcache/servers/@

PKG_GROUPS+=		${DQCACHE_GROUP}
PKG_USERS+=		${DQCACHE_USER}:${DQCACHE_GROUP}
BUILD_DEFS+=		DQCACHE_GROUP DQCACHE_USER PKG_SYSCONFBASE

RCD_SCRIPTS=		dqcache
FILES_SUBST+=		DQCACHE_USER=${DQCACHE_USER:Q}
FILES_SUBST+=		PKGNAME=${PKGNAME:Q}

LDFLAGS.SunOS+=		-lsocket

INSTALLATION_DIRS+=	bin sbin man/man1 man/man8 ${EGDIR}

post-install:
	for i in ${WRKSRC}/man/dq*.1; do \
		${INSTALL_MAN} $$i ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/; \
	done
	for i in ${WRKSRC}/man/dq*.8; do \
		${INSTALL_MAN} $$i ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/; \
	done
	for i in examples.md dnscurveroots.global; do \
		${INSTALL_DATA} ${FILESDIR}/$$i ${DESTDIR}${PREFIX}/${EGDIR}/; \
	done

.include "../../mk/bsd.pkg.mk"
