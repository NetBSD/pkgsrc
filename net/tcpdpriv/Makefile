# $NetBSD: Makefile,v 1.3 2003/06/02 01:17:42 jschauma Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdpriv-0.8
WRKSRC=		${WRKDIR}/${DISTNAME}/wide-tcpdpriv
CATEGORIES=	net
MASTER_SITES=	ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	anonymize tcpdump traces

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdpriv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcpdpriv.1 ${PREFIX}/man/man1

.include <../../mk/bsd.pkg.mk>
