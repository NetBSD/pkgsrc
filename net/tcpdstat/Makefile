# $NetBSD: Makefile,v 1.7 2004/07/10 09:07:22 grant Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdstat-0.8
CATEGORIES=	net
MASTER_SITES=	ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Analyze tcpdump output

WRKSRC=		${WRKDIR}/${DISTNAME}/tcpdstat
MAKE_ENV=	BINDIR=${PREFIX}/bin
USE_BUILDLINK3=	yes

.include <../../mk/bsd.pkg.mk>
