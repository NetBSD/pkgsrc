# $NetBSD: Makefile,v 1.7 2024/05/09 01:31:59 pho Exp $

DISTNAME=	hw-prim-0.6.3.2
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Primitive functions and data types
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring	\
	deepseq		\
	ghc-prim

.include "../../devel/hs-mmap/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
