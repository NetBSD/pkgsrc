# $NetBSD: Makefile,v 1.42 2005/03/23 01:48:06 schmonz Exp $
# FreeBSD Id: ports/net/djbdns/Makefile,v 1.4 2000/09/28 18:18:41 nbm Exp
#

DISTNAME=		djbdns-1.05
PKGREVISION=		6
CATEGORIES=		net
MASTER_SITES=		http://cr.yp.to/djbdns/	ftp://cr.yp.to/djbdns/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${MANPAGES}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/djbdns.html
COMMENT=		Collection of secure and reliable DNS tools

MANPAGES=		djbdns-1.05-man-20031023.tar.gz
SITES_${MANPAGES}=	http://smarden.org/pape/djb/manpages/

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

# We change conf-home from the default "/usr/local" and don't
# provide compatibility symlinks. We also patch to honor PKG_SYSCONFDIR
# and to set reasonable permissions on standard pkgsrc directories.
DJB_RESTRICTED=		YES

EGDIR=			${PREFIX}/share/examples/djbdns
CFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""
USE_PKGINSTALL=		yes
MAKE_DIRS+=		${PKG_SYSCONFDIR}
SUPPORT_FILES+=		${EGDIR}/dnsroots.global ${PKG_SYSCONFDIR}/dnsroots.global
PLIST_SRC=		${PKGDIR}/PLIST

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		3.0
.endif

INSTALLATION_DIRS=	bin man man/man1 man/man5 man/man8 share/examples/djbdns

.include "options.mk"

post-install:
	cd ${WRKDIR}/djbdns-man; for i in 1 5 8; do			 \
	for j in *.$$i; do ${INSTALL_MAN} $$j ${PREFIX}/man/man$$i; done \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
