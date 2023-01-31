# $NetBSD: Makefile,v 1.1 2023/01/31 18:43:22 pho Exp $

DISTNAME=	apply-refact-0.12.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perform refactorings specified by the refact library
LICENSE=	modified-bsd

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
