# $NetBSD: Makefile,v 1.8 2004/07/10 09:04:57 grant Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdpriv-0.8
CATEGORIES=	net
MASTER_SITES=	ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Anonymize tcpdump traces

WRKSRC=		${WRKDIR}/${DISTNAME}/wide-tcpdpriv
USE_BULDLINK3=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdpriv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcpdpriv.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
