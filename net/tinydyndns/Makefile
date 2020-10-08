# $NetBSD: Makefile,v 1.1 2020/10/08 17:38:38 schmonz Exp $

DISTNAME=		tinydyndns-0.4.2
DJBDNS_DISTNAME=	djbdns-1.05
CATEGORIES=		net
MASTER_SITES=		${HOMEPAGE}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${DJBDNS_DISTNAME}${EXTRACT_SUFX}
SITES.${DJBDNS_DISTNAME}${EXTRACT_SUFX}= http://cr.yp.to/djbdns/ ftp://cr.yp.to/djbdns/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://smarden.org/tinydyndns/
COMMENT=		Simple and powerful dynamic DNS solution
LICENSE=		modified-bsd

DEPENDS+=		qmail-[0-9]*:../../mail/qmail
DEPENDS+=		cvm-[0-9]*:../../security/cvm
DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

WRKSRC=			${WRKDIR}/${DJBDNS_DISTNAME}
MAKE_FILE=		Makefile.tinydyndns
BUILD_TARGET=		tinydyndns

DJB_RESTRICTED=		no

SUBST_CLASSES+=		djberrno

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

post-extract:
	cd ${WRKDIR} && mv ${PKGNAME_NOREV}/* ${DJBDNS_DISTNAME}

do-install:
	cd ${WRKSRC} && for i in conf data update; do			\
	  ${INSTALL_PROGRAM} tinydyndns-$$i ${DESTDIR}${PREFIX}/bin;	\
	  ${INSTALL_MAN} tinydyndns-$$i.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8; \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
