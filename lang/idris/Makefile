# $NetBSD: Makefile,v 1.7 2022/01/18 02:48:17 pho Exp $

DISTNAME=	idris-1.3.3
PKGNAME=	${DISTNAME}
PKGREVISION=	3
CATEGORIES=	lang

MAINTAINER=	pho@cielonegro.org
COMMENT=	Functional Programming Language with Dependent Types
LICENSE=	modified-bsd

CONFIGURE_ARGS+=	-f release

# ${WRKSRC}/Setup.hs has a postBuild hook that invokes gmake to build
# its standard libraries.
USE_TOOLS+=		gmake
SUBST_CLASSES+=		tools
SUBST_STAGE.tools=	pre-configure
SUBST_FILES.tools=	Setup.hs
SUBST_VARS.tools=	GMAKE PKGMANDIR PKGSRC_SETENV

# ${WRKSRC}/src/IRTS/System.hs has several hardcoded paths to be used at
# run time.
SUBST_CLASSES+=		runtime
SUBST_STAGE.runtime=	pre-configure
SUBST_FILES.runtime=	src/IRTS/System.hs
SUBST_VARS.runtime=	CC PREFIX COMPILER_RPATH_FLAG

# When -O2 is in effect, GHC 8.8.1 uses whopping 1 TiB of virtual
# memory (what?) to compile src/Idris/IBC.hs for some unknown reason,
# possibly related to https://gitlab.haskell.org/ghc/ghc/issues/5642
# or https://gitlab.haskell.org/ghc/ghc/issues/13535
HASKELL_OPTIMIZATION_LEVEL=	1

# Parallelization is unsafe because of the high memory consumption
# even with -O1. Setting it to -O0 may seem desirable, but that makes
# the resulting compiler way too slow.
MAKE_JOBS_SAFE=	NO

.include "options.mk"

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-annotated-wl-pprint/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-ansi-wl-pprint/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../textproc/hs-cheapskate/buildlink3.mk"
.include "../../devel/hs-code-page/buildlink3.mk"
.include "../../devel/hs-fingertree/buildlink3.mk"
.include "../../devel/hs-fsnotify/buildlink3.mk"
.include "../../math/hs-ieee754/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../devel/hs-terminal-size/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-vector-binary-instances/buildlink3.mk"
.include "../../archivers/hs-zip-archive/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
