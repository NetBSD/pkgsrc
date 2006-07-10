# $NetBSD: Makefile,v 1.17 2006/07/10 22:59:26 jlam Exp $
#

DISTNAME=		djbdns-run-20050415
CATEGORIES=		net
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
COMMENT=		Configures djbdns to cache and serve queries

DEPENDS_DJBDNS=		djbdns>=1.05nb5:../../net/djbdns
DEPENDS+=		${DEPENDS_DJBDNS}
DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		ucspi-tcp-[0-9]*:../../net/ucspi-tcp

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}
NO_CHECKSUM=		yes
NO_BUILD=		yes

MAKE_DIRS+=		${PKG_SYSCONFDIR}/axfrdns
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dnscache/ip
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dnscache/servers
MAKE_DIRS+=		${PKG_SYSCONFDIR}/rbldns
MAKE_DIRS+=		${PKG_SYSCONFDIR}/tinydns
PKG_GROUPS=		djbdns
PKG_USERS+=		dnslog:djbdns
PKG_USERS+=		axfrdns:djbdns
PKG_USERS+=		dnscache:djbdns
PKG_USERS+=		rbldns:djbdns
PKG_USERS+=		tinydns:djbdns
RCD_SCRIPTS=		axfrdns djbdns dnscache rbldns tinydns
FILES_SUBST+=		PKGNAME=${PKGNAME:Q}

INSTALLATION_DIRS=	bin share/doc/djbdns-run

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
	${INSTALL_DATA} ${FILESDIR}/README.pkgsrc ${PREFIX}/share/doc/djbdns-run

.include "../../mk/bsd.pkg.mk"
