# $NetBSD: Makefile,v 1.10 2005/06/17 03:50:28 jlam Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdpriv-0.8
CATEGORIES=	net
MASTER_SITES=	ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Anonymize tcpdump traces

WRKSRC=		${WRKDIR}/${DISTNAME}/wide-tcpdpriv

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdpriv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcpdpriv.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
