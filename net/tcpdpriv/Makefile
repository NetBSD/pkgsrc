# $NetBSD: Makefile,v 1.4 2003/07/17 22:51:54 grant Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdpriv-0.8
WRKSRC=		${WRKDIR}/${DISTNAME}/wide-tcpdpriv
CATEGORIES=	net
MASTER_SITES=	ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	anonymize tcpdump traces

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdpriv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcpdpriv.1 ${PREFIX}/man/man1

.include <../../mk/bsd.pkg.mk>
