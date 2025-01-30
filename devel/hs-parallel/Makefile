# $NetBSD: Makefile,v 1.9 2025/01/30 05:28:36 pho Exp $

DISTNAME=	parallel-3.2.2.0
PKGREVISION=	5
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
