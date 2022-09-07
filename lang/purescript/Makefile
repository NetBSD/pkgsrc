# $NetBSD: Makefile,v 1.7 2022/09/07 06:50:53 pho Exp $

DISTNAME=	purescript-0.15.4
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.purescript.org/
COMMENT=	Strongly typed programming language that compiles to JavaScript
LICENSE=	modified-bsd

USE_TOOLS+=	happy

CONFIGURE_ARGS+=	-f release

# If purs is to be linked dynamically, it will depend on more than 180
# shared objects and the dynamic linker will spend several seconds to
# resolve symbols on startup. This is unacceptable because purs tends to be
# launched very frequently by build systems. This wastes storage, but time
# is more expensive than disks.
HASKELL_ENABLE_SHARED_LIBRARY=	no

# It makes no sense to build the profiling library because this package
# isn't meant to be used as a library.
HASKELL_ENABLE_LIBRARY_PROFILING=	no

# purs is built with optparse-applicative, and can generate shell
# completion scripts automatically.
OPTPARSE_APPLICATIVE_EXECUTABLES+=	purs
.include "../../devel/hs-optparse-applicative/application.mk"

# Relax version constraints.
SUBST_CLASSES+=		cabal
SUBST_STAGE.cabal=	post-extract
SUBST_FILES.cabal=	purescript.cabal
#   These constraints can only be resolved with GHC 9.2.3 which we haven't
#   packaged yet.
SUBST_SED.cabal+=	-e 's/Cabal >=3.6.3.0 && <3.7/Cabal/'
SUBST_SED.cabal+=	-e 's/base >=4.16.2.0 && <4.17/base/'
SUBST_SED.cabal+=	-e 's/bytestring >=0.11.3.1 && <0.12/bytestring/'
SUBST_SED.cabal+=	-e 's/deepseq >=1.4.6.1 && <1.5/deepseq/'
SUBST_SED.cabal+=	-e 's/filepath >=1.4.2.2 && <1.5/filepath/'
SUBST_SED.cabal+=	-e 's/parsec >=3.1.15.0 && <3.2/parsec/'
SUBST_SED.cabal+=	-e 's/stm >=2.5.0.2 && <2.6/stm/'
SUBST_SED.cabal+=	-e 's/process ==1.6.13.1/process/'
#   These constraints can only be resolved with older packages than what we
#   provide.
SUBST_SED.cabal+=	-e 's/aeson >=2.0.3.0 && <2.1/aeson/'
SUBST_SED.cabal+=	-e 's/language-javascript ==0.7.0.0/language-javascript/'
SUBST_SED.cabal+=	-e 's/lens >=5.1.1 && <5.2/lens/'
SUBST_SED.cabal+=	-e 's/memory >=0.17.0 && <0.18/memory/'
SUBST_SED.cabal+=	-e 's/vector >=0.12.3.1 && <0.13/vector/'

# lib:purescript
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-better-errors/buildlink3.mk"
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../www/hs-bower-json/buildlink3.mk"
.include "../../textproc/hs-boxes/buildlink3.mk"
.include "../../devel/hs-cborg/buildlink3.mk"
.include "../../textproc/hs-cheapskate/buildlink3.mk"
.include "../../time/hs-clock/buildlink3.mk"
.include "../../security/hs-cryptonite/buildlink3.mk"
.include "../../devel/hs-data-ordlist/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../textproc/hs-edit-distance/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../devel/hs-fsnotify/buildlink3.mk"
.include "../../textproc/hs-Glob/buildlink3.mk"
.include "../../lang/hs-language-javascript/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lifted-async/buildlink3.mk"
.include "../../devel/hs-lifted-base/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-monad-logger/buildlink3.mk"
.include "../../devel/hs-monoidal-containers/buildlink3.mk"
.include "../../devel/hs-parallel/buildlink3.mk"
.include "../../devel/hs-pattern-arrows/buildlink3.mk"
.include "../../devel/hs-protolude/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-semialign/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-serialise/buildlink3.mk"
.include "../../lang/hs-sourcemap/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../textproc/hs-stringsearch/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-these/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../sysutils/hs-typed-process/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"

# exe:purescript
.include "../../textproc/hs-ansi-wl-pprint/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-wai-websockets/buildlink3.mk"
.include "../../www/hs-warp/buildlink3.mk"
.include "../../www/hs-websockets/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
