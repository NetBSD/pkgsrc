# $NetBSD: Makefile,v 1.10 2023/02/07 01:41:14 pho Exp $

DISTNAME=	text-short-0.1.5
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Memory-efficient representation of Unicode text strings
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	ghc-prim	\
	template-haskell

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
