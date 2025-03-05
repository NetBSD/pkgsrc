# $NetBSD: Makefile,v 1.17 2025/03/05 03:40:04 pho Exp $

DISTNAME=	text-short-0.1.6
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Memory-efficient representation of Unicode text strings
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	hashable	\
	template-haskell

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
