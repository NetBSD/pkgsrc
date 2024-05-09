# $NetBSD: Makefile,v 1.7 2024/05/09 01:32:12 pho Exp $

DISTNAME=	singleton-bool-0.1.7
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Type level booleans
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	deepseq

.include "../../devel/hs-boring/buildlink3.mk"
.include "../../devel/hs-dec/buildlink3.mk"
.include "../../devel/hs-some/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
