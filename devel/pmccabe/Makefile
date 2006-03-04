# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:26 jlam Exp $

DISTNAME=	pmccabe_2.2-3
PKGNAME=	pmccabe-2.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/p/pmccabe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Measures the McCabe cyclomatic complexity of C and C++

WRKSRC=		${WRKDIR}/pmccabe

CFLAGS+=	-D__unix=1

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
