# $NetBSD: Makefile,v 1.3 2023/05/24 16:05:38 bacon Exp $

DISTNAME=	fasda-0.1.2.30
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	aea98dcf93f5d124c007a1607752bc8f5dfb62f9

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/fasda
COMMENT=	Fast and simple differential analysis
LICENSE=	2-clause-bsd

LDFLAGS.SunOS+=	-lresolv

pre-build:
	cd ${WRKSRC} && make depend PREFIX=${PREFIX}

.include "../../biology/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
