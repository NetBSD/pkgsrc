# $NetBSD: Makefile,v 1.10 2005/09/28 20:52:24 rillig Exp $
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

USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL+=	${PKGDIR}/INSTALL
MAKE_DIRS+=		${PKG_SYSCONFDIR}/axfrdns
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dnscache/ip
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dnscache/servers
MAKE_DIRS+=		${PKG_SYSCONFDIR}/rbldns
MAKE_DIRS+=		${PKG_SYSCONFDIR}/tinydns
PKG_GROUPS=		djbdns
PKG_USERS+=		dnslog:djbdns::dnslog
PKG_USERS+=		axfrdns:djbdns::axfrdns
PKG_USERS+=		dnscache:djbdns::dnscache
PKG_USERS+=		rbldns:djbdns::rbldns
PKG_USERS+=		tinydns:djbdns::tinydns
RCD_SCRIPTS=		axfrdns djbdns dnscache rbldns tinydns
FILES_SUBST+=		PKGNAME=${PKGNAME}

INSTALLATION_DIRS=	bin share/doc/djbdns-run

.include "../../mk/bsd.prefs.mk"

# Detect the PKG_SYSCONFDIR of the installed djbdns, so we can create
# config files there and refer to them from rc.d scripts.
.if !empty(PHASES_AFTER_EXTRACT:M${PKG_PHASE})
INSTALLED_DJBDNS!= ${PKG_BEST_EXISTS} ${DEPENDS_DJBDNS:C/:.*$//:Q:S/\ / /g}
.  if empty(INSTALLED_DJBDNS:M*_not_found_)
.    if !defined(PKG_SYSCONFDIR.djbdns-run)
PKG_SYSCONFDIR.djbdns-run!= ${PKG_INFO} -Q PKG_SYSCONFDIR ${INSTALLED_DJBDNS}
.    endif
.  endif
.endif

do-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/README.pkgsrc		\
		> ${WRKDIR}/README.pkgsrc

do-install:
	${INSTALL_DATA} ${WRKDIR}/README.pkgsrc ${PREFIX}/share/doc/djbdns-run

.include "../../mk/bsd.pkg.mk"
