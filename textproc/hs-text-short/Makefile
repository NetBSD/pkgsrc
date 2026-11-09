# $NetBSD: Makefile,v 1.19 2026/11/09 09:11:39 pho Exp $

DISTNAME=	text-short-0.1.6
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Memory-efficient representation of Unicode text strings
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	ghc-prim	\
	hashable	\
	template-haskell

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
