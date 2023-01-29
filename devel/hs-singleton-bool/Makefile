# $NetBSD: Makefile,v 1.1 2023/01/29 04:46:22 pho Exp $

DISTNAME=	singleton-bool-0.1.6
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Type level booleans
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../devel/hs-boring/buildlink3.mk"
.include "../../devel/hs-dec/buildlink3.mk"
.include "../../devel/hs-some/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
