# $NetBSD: Makefile,v 1.1.1.1 2002/10/30 21:13:35 itojun Exp $
#

DISTNAME=	dnstop
PKGNAME=	dnstop-20021030
CATEGORIES=	net
MASTER_SITES=	http://dnstop.measurement-factory.com/src/
DISTFILES=	dnstop.c Makefile

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://dnstop.measurement-factory.com/src/
COMMENT=	Diagnose tcpdump trace for DNS queries/replies

WRKSRC=		${WRKDIR}

do-extract:
	${CP} ${DISTDIR}/dnstop.c ${DISTDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
