# $NetBSD: Makefile,v 1.3 2025/01/31 10:46:15 pho Exp $

DISTNAME=	extensions-0.1.0.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parse Haskell Language Extensions
LICENSE=	mpl-2.0

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	containers	\
	filepath	\
	ghc-boot-th	\
	optparse-applicative

OPTPARSE_APPLICATIVE_EXECUTABLES+=	\
	extensions

# lib:extensions
# ... has no dependencies on pkgsrc packages aside from GHC

# exe:extensions
.include "../../devel/hs-colourista/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/application.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
