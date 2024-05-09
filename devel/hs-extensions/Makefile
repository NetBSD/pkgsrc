# $NetBSD: Makefile,v 1.2 2024/05/09 01:31:53 pho Exp $

# NOTE: Cannot update to >=0.1.0.2 because they depend on GHC 10.
DISTNAME=	extensions-0.1.0.1
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parse Haskell Language Extensions
LICENSE=	mpl-2.0

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
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
