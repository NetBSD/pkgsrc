# $NetBSD: Makefile,v 1.12 2025/08/13 11:06:52 pho Exp $

DISTNAME=	parallel-3.2.2.0
PKGREVISION=	8
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
