# $NetBSD: Makefile,v 1.1.1.1 2004/09/01 20:13:04 schmonz Exp $
#

DISTNAME=		djbdns-run-20040901
CATEGORIES=		net
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
COMMENT=		Configures djbdns to cache and serve queries

DEPENDS_DJBDNS=		djbdns>=1.05nb5:../../net/djbdns
DEPENDS+=		${DEPENDS_DJBDNS}
DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		ucspi-tcp-[0-9]*:../../net/ucspi-tcp

CONFLICTS+=		djbdns<=1.05nb4

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}
NO_CHECKSUM=		# defined

USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL+=	${PKGDIR}/INSTALL
MAKE_DIRS+=		${PKG_SYSCONFDIR}/axfrdns
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dnscache/ip
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dnscache/servers
MAKE_DIRS+=		${PKG_SYSCONFDIR}/tinydns
PKG_GROUPS=		djbdns
PKG_USERS+=		Gdnslog:djbdns::dnslog
PKG_USERS+=		Gaxfrdns:djbdns::axfrdns
PKG_USERS+=		Gdnscache:djbdns::dnscache
PKG_USERS+=		Gtinydns:djbdns::tinydns
RCD_SCRIPTS=		axfrdns dnscache tinydns
FILES_SUBST+=		PKGNAME=${PKGNAME}

INSTALLATION_DIRS=	bin share/doc/djbdns-run

.include "../../mk/bsd.prefs.mk"

# Detect the PKG_SYSCONFDIR of the installed djbdns, so we can create
# config files there and refer to them from rc.d scripts.
.if !empty(PHASES_AFTER_EXTRACT:M${PKG_PHASE})
INSTALLED_DJBDNS!= ${PKG_BEST_EXISTS} ${DEPENDS_DJBDNS:C/:.*$//:Q:S/\ / /g}
.  if empty(INSTALLED_DJBDNS:M*_not_found_)
.    if !defined(PKG_SYSCONFDIR.djbdns-run)
PKG_SYSCONFDIR.djbdns-run!= \
	${PKG_INFO} -qB ${INSTALLED_DJBDNS} |				\
		${SED} -n '/^PKG_SYSCONFDIR=/s|^PKG_SYSCONFDIR=[ 	]*||p'
.    endif
.  endif
.endif

do-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/README.pkgsrc		\
		> ${WRKDIR}/README.pkgsrc
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/dnscache-showctl.sh	\
		> ${WRKDIR}/dnscache-showctl
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/tinydns-showctl.sh	\
		> ${WRKDIR}/tinydns-showctl

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/dnscache-showctl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/tinydns-showctl ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/README.pkgsrc ${PREFIX}/share/doc/djbdns-run

.include "../../mk/bsd.pkg.mk"
