# $NetBSD: Makefile,v 1.10 2025/02/02 13:05:17 pho Exp $

DISTNAME=	parallel-3.2.2.0
PKGREVISION=	6
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parallel programming library
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base \
	containers	\
	deepseq

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
