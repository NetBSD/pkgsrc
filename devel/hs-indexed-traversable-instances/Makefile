# $NetBSD: Makefile,v 1.9 2023/11/02 06:36:42 pho Exp $

DISTNAME=	indexed-traversable-instances-0.1.1.2
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	More instances of type classes from indexed-traversable
LICENSE=	2-clause-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../devel/hs-OneTuple/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
