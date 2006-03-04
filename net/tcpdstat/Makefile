# $NetBSD: Makefile,v 1.12 2006/03/04 21:30:24 jlam Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdstat-0.8
CATEGORIES=	net
MASTER_SITES=	ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Analyze tcpdump output

NOT_FOR_PLATFORM=	Interix-*-*

WRKSRC=		${WRKDIR}/${DISTNAME}/tcpdstat
MAKE_ENV+=	BINDIR=${PREFIX:Q}/bin

.include "../../mk/bsd.pkg.mk"
