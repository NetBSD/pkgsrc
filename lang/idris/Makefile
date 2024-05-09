# $NetBSD: Makefile,v 1.23 2024/05/09 01:32:24 pho Exp $

DISTNAME=	idris-1.3.4
PKGNAME=	${DISTNAME}
PKGREVISION=	10
CATEGORIES=	lang

MAINTAINER=	pho@cielonegro.org
COMMENT=	Functional Programming Language with Dependent Types
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	aeson			\
	ansi-terminal		\
	ansi-wl-pprint		\
	bytestring		\
	deepseq			\
	fsnotify		\
	libffi			\
	mtl			\
	network			\
	optparse-applicative	\
	text			\
	transformers		\
	unix			\
	vector

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

# When -O2 is in effect, GHC uses whopping 4 GiB of memory (what?) to
# compile src/Idris/IBC.hs for some unknown reason, possibly related to
# https://gitlab.haskell.org/ghc/ghc/issues/5642 or
# https://gitlab.haskell.org/ghc/ghc/issues/13535
HASKELL_OPTIMIZATION_LEVEL=	1

# If idris is to be linked dynamically, it will depend on more than 110
# shared objects and the dynamic linker will spend nearly a second to
# resolve symbols on startup. This is unacceptable because idris tends to
# be launched very frequently by build systems. This wastes storage, but
# time is more expensive than disks.
HASKELL_ENABLE_SHARED_LIBRARY=	no

# It makes no sense to build the profiling library because this package
# isn't meant to be used as a library.
HASKELL_ENABLE_LIBRARY_PROFILING=	no

# idris is built with optparse-applicative, and can generate shell
# completion scripts automatically.
.include "../../devel/hs-optparse-applicative/application.mk"

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
