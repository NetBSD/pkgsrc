# $NetBSD: Makefile,v 1.4 2006/01/09 18:32:39 joerg Exp $

DISTNAME=	pmccabe_2.2-3
PKGNAME=	pmccabe-2.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/p/pmccabe/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Measures the McCabe cyclomatic complexity of C and C++

WRKSRC=		${WRKDIR}/pmccabe

CFLAGS+=	-D__unix=1

.include "../../mk/bsd.pkg.mk"
