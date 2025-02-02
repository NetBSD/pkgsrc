# $NetBSD: Makefile,v 1.13 2025/02/02 13:05:59 pho Exp $

DISTNAME=	unicode-collation-0.1.3.6
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Haskell implementation of the Unicode Collation Algorithm
LICENSE=	2-clause-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../devel/hs-th-lift-instances/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
