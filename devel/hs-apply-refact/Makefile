# $NetBSD: Makefile,v 1.9 2025/02/02 13:04:56 pho Exp $

DISTNAME=	apply-refact-0.14.0.0
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perform refactorings specified by the refact library
LICENSE=	modified-bsd

BROKEN+=	"apply-refact is incompatible with GHC 9.10."
# It supports 9.12 though. No idea why the upstream skipped 9.10.

OPTPARSE_APPLICATIVE_EXECUTABLES+=	refactor

# lib:apply-refact
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../sysutils/hs-filemanip/buildlink3.mk"
.include "../../devel/hs-ghc-exactprint/buildlink3.mk"
.include "../../devel/hs-refact/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"

# exe:refactor
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/application.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
