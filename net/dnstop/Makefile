# $NetBSD: Makefile,v 1.5 2003/04/23 16:38:49 wiz Exp $
#

DISTNAME=	dnstop-20021224
PKGREVISION=	1
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	http://dnstop.measurement-factory.com/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} dnstop.8

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://dnstop.measurement-factory.com/src/
COMMENT=	Diagnose tcpdump trace for DNS queries/replies

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${PREFIX}/bin
	${INSTALL_MAN} ${DISTDIR}/dnstop.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dnstop
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/dnstop

.include "../../mk/bsd.pkg.mk"
