# $NetBSD: Makefile,v 1.13 2026/11/13 14:39:10 pho Exp $

DISTNAME=	parallel-3.2.2.0
PKGREVISION=	9
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
