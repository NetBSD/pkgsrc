# $NetBSD: Makefile,v 1.15 2025/08/13 11:07:38 pho Exp $

DISTNAME=	unicode-collation-0.1.3.6
PKGREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Haskell implementation of the Unicode Collation Algorithm
LICENSE=	2-clause-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../devel/hs-th-lift-instances/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
