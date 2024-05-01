# $NetBSD: Makefile,v 1.7 2024/05/01 17:02:37 pho Exp $

DISTNAME=	parsers-0.12.11
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parsing combinators
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../textproc/hs-charset/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
