# $NetBSD: Makefile,v 1.2 2003/03/29 12:42:04 jmmv Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdpriv-0.8
WRKSRC=		${WRKDIR}/${DISTNAME}/wide-tcpdpriv
CATEGORIES=	net
MASTER_SITES=	ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	packages@netbsd.org
COMMENT=	anonymize tcpdump traces

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdpriv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcpdpriv.1 ${PREFIX}/man/man1

.include <../../mk/bsd.pkg.mk>
