# $NetBSD: Makefile,v 1.64 2017/06/22 12:37:33 schmonz Exp $

DISTNAME=		djbdns-1.05
PKGREVISION=		11
CATEGORIES=		net
MASTER_SITES=		http://cr.yp.to/djbdns/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${MANPAGES}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/djbdns.html
COMMENT=		Collection of secure and reliable DNS tools
LICENSE=		public-domain

MANPAGES=		${DISTNAME}-man-20031023.tar.gz
SITES.${MANPAGES}=	http://smarden.org/pape/djb/manpages/

DJB_RESTRICTED=		no

EGDIR=			${PREFIX}/share/examples/djbdns
CFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""
MAKE_DIRS+=		${PKG_SYSCONFDIR}
CONF_FILES+=		${EGDIR}/dnsroots.global ${PKG_SYSCONFDIR}/dnsroots.global
PLIST_SRC=		${PKGDIR}/PLIST

INSTALLATION_DIRS=	bin man ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 share/examples/djbdns

post-install:
	cd ${WRKDIR}/${PKGBASE}-man; for i in 1 5 8; do		 	\
		for j in *.$$i; do ${INSTALL_MAN} $$j			\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man$$i; done	\
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
