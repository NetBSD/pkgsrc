# $NetBSD: Makefile,v 1.2 2025/02/02 13:05:40 pho Exp $

DISTNAME=	modern-uri-0.3.6.1
PKGREVISION=	1
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modern library for working with URIs
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring	\
	containers	\
	deepseq	\
	template-haskell	\
	text

.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../devel/hs-reflection/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
