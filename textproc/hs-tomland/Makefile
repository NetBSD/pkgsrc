# $NetBSD: Makefile,v 1.1 2024/05/05 08:21:18 pho Exp $

DISTNAME=	tomland-1.3.3.2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bidirectional TOML serialization
LICENSE=	mpl-2.0

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base		\
	bytestring	\
	deepseq		\
	megaparsec	\
	mtl		\
	text		\
	validation-selective

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-validation-selective/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
