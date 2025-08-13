# $NetBSD: Makefile,v 1.9 2025/08/13 11:06:45 pho Exp $

DISTNAME=	hw-fingertree-0.1.2.1
PKGREVISION=	7
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Generic finger-tree structure, with example instances
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	deepseq

.include "../../devel/hs-hw-prim/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
