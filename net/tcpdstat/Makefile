# $NetBSD: Makefile,v 1.11 2005/12/05 20:50:49 rillig Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdstat-0.8
CATEGORIES=	net
MASTER_SITES=	ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Analyze tcpdump output

NOT_FOR_PLATFORM=	Interix-*-*

WRKSRC=		${WRKDIR}/${DISTNAME}/tcpdstat
MAKE_ENV+=	BINDIR=${PREFIX:Q}/bin

.include "../../mk/bsd.pkg.mk"
