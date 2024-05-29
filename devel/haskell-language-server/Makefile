# $NetBSD: Makefile,v 1.17 2024/05/29 16:32:03 adam Exp $

DISTNAME=	haskell-language-server-2.7.0.0
PKGNAME=	${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	LSP server for GHC
LICENSE=	apache-2.0

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	Diff	\
	lsp	\
	lsp-types

# HLS is built with optparse-applicative, and can generate shell completion
# scripts automatically.
OPTPARSE_APPLICATIVE_EXECUTABLES+=	haskell-language-server
OPTPARSE_APPLICATIVE_EXECUTABLES+=	haskell-language-server-wrapper
.include "../../devel/hs-optparse-applicative/application.mk"

#
# These contains a lot of duplicate dependencies but it's intentional so
# that we can easily maintain the list.
#
# lib:haskell-language-server
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-githash/buildlink3.mk"
.include "../../devel/hs-hie-bios/buildlink3.mk"
.include "../../devel/hs-hiedb/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-optparse-simple/buildlink3.mk"
.include "../../textproc/hs-prettyprinter/buildlink3.mk"

# lib:hls-cabal-fmt-plugin
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../sysutils/hs-process-extras/buildlink3.mk"

# lib:hls-cabal-plugin
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../textproc/hs-text-rope/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"

# lib:hls-class-plugin
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghc-exactprint/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"

# lib:hls-call-hierarchy-plugin
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hiedb/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../databases/hs-sqlite-simple/buildlink3.mk"

# lib:hls-eval-plugin
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.include "../../devel/hs-unliftio/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"

# lib:hls-explicit-imports-plugin
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"

# lib:hls-rename-plugin
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-hie-compat/buildlink3.mk"
.include "../../devel/hs-hiedb/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../math/hs-mod/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"

# lib:hls-retrie-plugin
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../devel/retrie/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"

# lib:hls-hlint-plugin
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-apply-refact/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser-ex/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hlint/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-refact/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"

# lib:hls-stan-plugin
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-hie-compat/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../devel/stan/buildlink3.mk"
.include "../../devel/hs-trial/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"

# lib:hls-module-name-plugin
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"

# lib:hls-pragmas-plugin
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../textproc/hs-fuzzy/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"

# lib:hls-splice-plugin
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-foldl/buildlink3.mk"
.include "../../devel/hs-ghc-exactprint/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"

# lib:hls-alternate-number-format-plugin
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"

# lib:hls-qualify-imported-names-plugin
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"

# lib:hls-code-range-plugin
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"

# lib:hls-change-type-signature-plugin
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"

# lib:hls-gadt-plugin
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghc-exactprint/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"

# lib:hls-explicit-fixity-plugin
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"

# lib:hls-explicit-record-fields-plugin
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"

# lib:hls-overloaded-record-dot-plugin
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"

# lib:hls-floskell-plugin
.include "../../devel/floskell/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"

# lib:hls-fourmolu-plugin
.include "../../devel/fourmolu/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../sysutils/hs-process-extras/buildlink3.mk"

# lib:hls-ormolu-plugin
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/ormolu/buildlink3.mk"
.include "../../sysutils/hs-process-extras/buildlink3.mk"

# lib:hls-stylish-haskell-plugin
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../devel/stylish-haskell/buildlink3.mk"

# lib:hls-refactor-plugin
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghc-exactprint/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-parser-combinators/buildlink3.mk"
.include "../../textproc/hs-regex-applicative/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/retrie/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"

# lib:hls-semantic-tokens-plugin
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-stm-containers/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../textproc/hs-text-rope/buildlink3.mk"

# exe:haskell-language-server
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../textproc/hs-prettyprinter/buildlink3.mk"

# exe:haskell-language-server-wrapper
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hie-bios/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
