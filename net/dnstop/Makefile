# $NetBSD: Makefile,v 1.10 2004/01/20 12:22:19 agc Exp $
#

DISTNAME=	dnstop-20021224
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://dnstop.measurement-factory.com/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} dnstop.8

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dnstop.measurement-factory.com/src/
COMMENT=	Diagnose tcpdump trace for DNS queries/replies

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PKGNAME_NOREV}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${PREFIX}/bin
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/dnstop.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dnstop
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/dnstop

.include "../../mk/bsd.pkg.mk"
