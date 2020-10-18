# $NetBSD: Makefile,v 1.4 2020/10/18 12:42:26 schmonz Exp $

DISTNAME=		tinydyndns-0.4.2
DJBDNS_DISTNAME=	djbdns-1.05
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${HOMEPAGE}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${DJBDNS_DISTNAME}${EXTRACT_SUFX}
SITES.${DJBDNS_DISTNAME}${EXTRACT_SUFX}= http://cr.yp.to/djbdns/ ftp://cr.yp.to/djbdns/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://smarden.org/tinydyndns/
COMMENT=		Simple and powerful dynamic DNS solution
LICENSE=		modified-bsd

DEPENDS+=		djbdns-[0-9]*:../../net/djbdns

WRKSRC=			${WRKDIR}/${DJBDNS_DISTNAME}

USE_TOOLS+=		gmake
MAKE_FILE=		Makefile.${PKGBASE}
BUILD_TARGET=		${PKGBASE}
INSTALL_TARGET=		install-${PKGBASE}

DJB_RESTRICTED=		no

SUBST_CLASSES+=		djberrno

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	${MAKE_FILE}
SUBST_SED.paths=	-e 's|/usr/local/bin/|${DESTDIR}${PREFIX}/bin/|g'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

post-extract:
	cd ${WRKDIR} && mv ${PKGNAME_NOREV}/* ${DJBDNS_DISTNAME}

post-install:
	cd ${WRKSRC} && for i in conf data update; do			\
	  ${INSTALL_MAN} ${PKGBASE}-$$i.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8; \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
