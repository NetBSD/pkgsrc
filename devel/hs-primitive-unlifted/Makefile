# $NetBSD: Makefile,v 1.3 2023/02/07 01:40:47 pho Exp $

# NOTE: Do not update this to 1.0. It does some shady things that are no
# longer valid on GHC 9. See:
# https://github.com/haskell-primitive/primitive-unlifted/issues/29
DISTNAME=	primitive-unlifted-0.1.3.1
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Primitive GHC types with unlifted types inside
LICENSE=	modified-bsd

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
