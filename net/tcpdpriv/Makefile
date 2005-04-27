# $NetBSD: Makefile,v 1.9 2005/04/27 20:49:47 hira Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdpriv-0.8
CATEGORIES=	net
MASTER_SITES=	ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Anonymize tcpdump traces

WRKSRC=		${WRKDIR}/${DISTNAME}/wide-tcpdpriv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdpriv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcpdpriv.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
