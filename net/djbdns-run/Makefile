# $NetBSD: Makefile,v 1.28 2017/08/05 15:16:05 schmonz Exp $
#

DISTNAME=		djbdns-run-20170805
CATEGORIES=		net
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
COMMENT=		Configures djbdns to cache and serve queries
LICENSE=		2-clause-bsd

DEPENDS_DJBDNS=		djbdns>=1.05nb5:../../net/djbdns
DEPENDS+=		${DEPENDS_DJBDNS}
DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		ucspi-tcp-[0-9]*:../../net/ucspi-tcp

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
NO_CHECKSUM=		yes

MAKE_DIRS+=		${PKG_SYSCONFDIR}/axfrdns
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dnscache/ip
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dnscache/servers
MAKE_DIRS+=		${PKG_SYSCONFDIR}/rbldns
MAKE_DIRS+=		${PKG_SYSCONFDIR}/tinydns
PKG_GROUPS=		${DJBDNS_DJBDNS_GROUP}
PKG_USERS+=		${DJBDNS_AXFR_USER}:${DJBDNS_DJBDNS_GROUP}
PKG_USERS+=		${DJBDNS_CACHE_USER}:${DJBDNS_DJBDNS_GROUP}
PKG_USERS+=		${DJBDNS_LOG_USER}:${DJBDNS_DJBDNS_GROUP}
PKG_USERS+=		${DJBDNS_RBL_USER}:${DJBDNS_DJBDNS_GROUP}
PKG_USERS+=		${DJBDNS_TINY_USER}:${DJBDNS_DJBDNS_GROUP}
RCD_SCRIPTS=		djbdns axfrdns dnscache rbldns tinydns
FILES_SUBST+=		DJBDNS_AXFR_USER=${DJBDNS_AXFR_USER:Q}
FILES_SUBST+=		DJBDNS_CACHE_USER=${DJBDNS_CACHE_USER:Q}
FILES_SUBST+=		DJBDNS_LOG_USER=${DJBDNS_LOG_USER:Q}
FILES_SUBST+=		DJBDNS_RBL_USER=${DJBDNS_RBL_USER:Q}
FILES_SUBST+=		DJBDNS_TINY_USER=${DJBDNS_TINY_USER:Q}
FILES_SUBST+=		PKGNAME=${PKGNAME:Q}

INSTALLATION_DIRS=	share/doc/djbdns-run
BUILD_DEFS+=		DJBDNS_AXFR_USER DJBDNS_CACHE_USER DJBDNS_LOG_USER
BUILD_DEFS+=		DJBDNS_RBL_USER DJBDNS_TINY_USER
BUILD_DEFS+=		DJBDNS_DJBDNS_GROUP

.include "../../mk/bsd.prefs.mk"

# Detect the PKG_SYSCONFDIR of the installed djbdns, so we can create
# config files there and refer to them from rc.d scripts.
#
.if !defined(PKG_SYSCONFDIR.djbdns-run)
PKG_SYSCONFDIR.djbdns-run!=						\
	${PKG_INFO} -Q PKG_SYSCONFDIR					\
		${DEPENDS_DJBDNS:C/:.*$//:Q} 2>/dev/null ||		\
	${ECHO} "PKG_SYSCONFDIR.djbdns-run_not_set"
.  if empty(PKG_SYSCONFDIR.djbdns-run:M*not_set)
MAKEVARS+=	PKG_SYSCONFDIR.djbdns-run
.  endif
.endif

do-install:
	${INSTALL_DATA} ${FILESDIR}/README.pkgsrc ${DESTDIR}${PREFIX}/share/doc/djbdns-run

.include "../../mk/bsd.pkg.mk"
