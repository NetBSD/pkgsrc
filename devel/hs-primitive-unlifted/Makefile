# $NetBSD: Makefile,v 1.7 2024/04/30 13:39:51 pho Exp $

DISTNAME=	primitive-unlifted-2.1.0.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Primitive GHC types with unlifted types inside
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
