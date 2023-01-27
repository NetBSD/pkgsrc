# $NetBSD: Makefile,v 1.6 2023/01/27 14:35:00 pho Exp $

DISTNAME=	fourmolu-0.10.1.0
PKGNAME=	${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Formatter for Haskell source code
LICENSE=	modified-bsd

# Do not parse the default fixity information via TemplateHaskell. It
# *might* produce a faster code but takes ridiculously long to compile and
# uses more than 3 GiB of memory.
CONFIGURE_ARGS+=	-f-fixity-th

# fourmolu is built with optparse-applicative, and can generate shell
# completion scripts automatically.
.include "../../devel/hs-optparse-applicative/application.mk"

# lib:fourmolu
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-memotrie/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-th-lift-instances/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk" # Needed because of -f-fixity-th

# exe:fourmolu
.include "../../devel/hs-gitrev/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
