# $NetBSD: Makefile,v 1.54 2008/02/19 13:59:05 schmonz Exp $

DISTNAME=		djbdns-1.05
PKGREVISION=		7
CATEGORIES=		net
MASTER_SITES=		http://cr.yp.to/djbdns/	ftp://cr.yp.to/djbdns/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${MANPAGES}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/djbdns.html
COMMENT=		Collection of secure and reliable DNS tools

MANPAGES=		${DISTNAME}-man-20031023.tar.gz
SITES.${MANPAGES}=	http://smarden.org/pape/djb/manpages/

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# We change conf-home from the default "/usr/local" and don't
# provide compatibility symlinks. We also patch to honor PKG_SYSCONFDIR
# and to set reasonable permissions on standard pkgsrc directories.
# This no longer affects distributability, as djbdns is public domain.
DJB_RESTRICTED=		no

EGDIR=			${PREFIX}/share/examples/djbdns
CFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""
MAKE_DIRS+=		${PKG_SYSCONFDIR}
CONF_FILES+=		${EGDIR}/dnsroots.global ${PKG_SYSCONFDIR}/dnsroots.global
PLIST_SRC=		${PKGDIR}/PLIST

INSTALLATION_DIRS=	bin man ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 share/examples/djbdns

post-install:
	cd ${WRKDIR}/*-man; for i in 1 5 8; do		 		\
	for j in *.$$i; do ${INSTALL_MAN} $$j ${PREFIX}/${PKGMANDIR}/man$$i; done \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
