# $NetBSD: Makefile,v 1.16 2024/05/09 01:32:24 pho Exp $

DISTNAME=	purescript-0.15.15
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.purescript.org/
COMMENT=	Strongly typed programming language that compiles to JavaScript
LICENSE=	modified-bsd

USE_TOOLS+=	happy

CONFIGURE_ARGS+=	-f release

# Use crypton instead of outdated cryptonite.
SUBST_CLASSES+=		crypton
SUBST_STAGE.crypton=	post-extract
SUBST_FILES.crypton=	purescript.cabal
SUBST_SED.crypton=	-e 's/cryptonite/crypton/g'

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	Cabal			\
	aeson			\
	ansi-terminal		\
	ansi-wl-pprint		\
	base			\
	bytestring		\
	crypton			\
	deepseq			\
	happy			\
	language-javascript	\
	lens			\
	memory			\
	mtl			\
	network			\
	optparse-applicative	\
	process			\
	semialign		\
	template-haskell	\
	text			\
	these			\
	time			\
	transformers		\
	vector

# If purs is to be linked dynamically, it will depend on more than 180
# shared objects and the dynamic linker will spend several seconds to
# resolve symbols on startup. This is unacceptable because purs tends to be
# launched very frequently by build systems. This wastes storage, but time
# is more expensive than disks.
HASKELL_ENABLE_DYNAMIC_EXECUTABLE=	no

# It makes no sense to build the profiling library because this package
# isn't meant to be used as a library.
HASKELL_ENABLE_LIBRARY_PROFILING=	no

# purs is built with optparse-applicative, and can generate shell
# completion scripts automatically.
OPTPARSE_APPLICATIVE_EXECUTABLES+=	purs
.include "../../devel/hs-optparse-applicative/application.mk"

# lib:purescript
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-better-errors/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../www/hs-bower-json/buildlink3.mk"
.include "../../textproc/hs-boxes/buildlink3.mk"
.include "../../devel/hs-cborg/buildlink3.mk"
.include "../../textproc/hs-cheapskate/buildlink3.mk"
.include "../../time/hs-clock/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../devel/hs-data-ordlist/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../textproc/hs-edit-distance/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
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
.include "../../textproc/hs-stringsearch/buildlink3.mk"
.include "../../devel/hs-these/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-witherable/buildlink3.mk"

# exe:purs
.include "../../textproc/hs-ansi-wl-pprint/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
