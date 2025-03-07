# $NetBSD: Makefile,v 1.1 2025/03/07 17:55:27 pho Exp $

DISTNAME=	stache-2.3.4
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Mustache templates for Haskell
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring	\
	containers	\
	deepseq	\
	filepath	\
	template-haskell	\
	text

# lib:stache
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"

# exe:stache
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-gitrev/buildlink3.mk"
OPTPARSE_APPLICATIVE_EXECUTABLES+=	\
	stache
.include "../../devel/hs-optparse-applicative/application.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
