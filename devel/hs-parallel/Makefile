# $NetBSD: Makefile,v 1.11 2025/03/05 03:39:23 pho Exp $

DISTNAME=	parallel-3.2.2.0
PKGREVISION=	7
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
