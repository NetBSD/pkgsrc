# $NetBSD: Makefile,v 1.12 2023/10/31 15:24:28 pho Exp $

DISTNAME=	haskell-language-server-2.4.0.0
PKGNAME=	${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	LSP server for GHC
LICENSE=	apache-2.0

# HLS is built with optparse-applicative, and can generate shell completion
# scripts automatically.
OPTPARSE_APPLICATIVE_EXECUTABLES+=	haskell-language-server
OPTPARSE_APPLICATIVE_EXECUTABLES+=	haskell-language-server-wrapper
.include "../../devel/hs-optparse-applicative/application.mk"

# lib:haskell-language-server
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../security/hs-cryptohash-sha1/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-githash/buildlink3.mk"
.include "../../devel/hs-hie-bios/buildlink3.mk"
.include "../../devel/hs-hiedb/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-optparse-simple/buildlink3.mk"
.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../databases/hs-sqlite-simple/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-hls-cabal-plugin/buildlink3.mk"
.include "../../devel/hs-hls-call-hierarchy-plugin/buildlink3.mk"
.include "../../devel/hs-hls-cabal-fmt-plugin/buildlink3.mk"
.include "../../devel/hs-hls-change-type-signature-plugin/buildlink3.mk"
.include "../../devel/hs-hls-class-plugin/buildlink3.mk"
.include "../../devel/hs-hls-eval-plugin/buildlink3.mk"
.include "../../devel/hs-hls-explicit-imports-plugin/buildlink3.mk"
.include "../../devel/hs-hls-rename-plugin/buildlink3.mk"
.include "../../devel/hs-hls-retrie-plugin/buildlink3.mk"
CONFIGURE_ARGS+=	-f-hlint
#.include "../../devel/hs-hls-hlint-plugin/buildlink3.mk" # Not buildable with ghc-lib-parser-9.8
.include "../../devel/hs-hls-module-name-plugin/buildlink3.mk"
.include "../../devel/hs-hls-pragmas-plugin/buildlink3.mk"
.include "../../devel/hs-hls-splice-plugin/buildlink3.mk"
.include "../../devel/hs-hls-alternate-number-format-plugin/buildlink3.mk"
.include "../../devel/hs-hls-qualify-imported-names-plugin/buildlink3.mk"
.include "../../devel/hs-hls-code-range-plugin/buildlink3.mk"
.include "../../devel/hs-hls-gadt-plugin/buildlink3.mk"
.include "../../devel/hs-hls-explicit-fixity-plugin/buildlink3.mk"
.include "../../devel/hs-hls-explicit-record-fields-plugin/buildlink3.mk"
#.include "../../devel/hs-hls-floskell-plugin/buildlink3.mk" # Not buildable with GHC >= 9.5
.include "../../devel/hs-hls-fourmolu-plugin/buildlink3.mk"
.include "../../devel/hs-hls-ormolu-plugin/buildlink3.mk"
CONFIGURE_ARGS+=	-f-stylishhaskell
#.include "../../devel/hs-hls-stylish-haskell-plugin/buildlink3.mk" # Not buildable with ghc-lib-parser-9.8
.include "../../devel/hs-hls-refactor-plugin/buildlink3.mk"
.include "../../devel/hs-hls-overloaded-record-dot-plugin/buildlink3.mk"

# exe:haskell-language-server
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"

# exe:haskell-language-server-wrapper
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../devel/hs-gitrev/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
