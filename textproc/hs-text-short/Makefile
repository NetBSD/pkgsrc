# $NetBSD: Makefile,v 1.14 2024/05/09 01:32:48 pho Exp $

DISTNAME=	text-short-0.1.5
PKGREVISION=	6
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Memory-efficient representation of Unicode text strings
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base			\
	bytestring		\
	deepseq			\
	ghc-prim		\
	template-haskell	\
	text

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
