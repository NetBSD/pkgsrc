# $NetBSD: Makefile,v 1.2 2002/12/25 00:44:46 wiz Exp $
#

DISTNAME=	dnstop-20021224
CATEGORIES=	net
MASTER_SITES=	http://dnstop.measurement-factory.com/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} dnstop.8

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://dnstop.measurement-factory.com/src/
COMMENT=	Diagnose tcpdump trace for DNS queries/replies

WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${PREFIX}/bin
	${INSTALL_MAN} ${DISTDIR}/dnstop.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dnstop
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/dnstop

.include "../../mk/bsd.pkg.mk"
