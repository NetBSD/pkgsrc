# $NetBSD: Makefile,v 1.1.1.1 2001/03/06 03:43:16 itojun Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdpriv-0.8
CATEGORIES=	net
MASTER_SITES=	ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	packages@netbsd.org
COMMENT=	anonymize tcpdump traces

WRKSRC=		${WRKDIR}/${DISTNAME}/wide-tcpdpriv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdpriv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcpdpriv.1 ${PREFIX}/man/man1

.include <../../mk/bsd.pkg.mk>
