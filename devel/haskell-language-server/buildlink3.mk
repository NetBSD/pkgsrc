# $NetBSD: buildlink3.mk,v 1.7 2023/02/01 02:15:49 pho Exp $

BUILDLINK_TREE+=	haskell-language-server

.if !defined(HASKELL_LANGUAGE_SERVER_BUILDLINK3_MK)
HASKELL_LANGUAGE_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.haskell-language-server+=	haskell-language-server>=1.9.0
BUILDLINK_ABI_DEPENDS.haskell-language-server+=	haskell-language-server>=1.9.0.0
BUILDLINK_PKGSRCDIR.haskell-language-server?=	../../devel/haskell-language-server

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
.include "../../devel/hs-hls-explicit-imports-plugin/buildlink3.mk"
.include "../../devel/hs-hls-refine-imports-plugin/buildlink3.mk"
.include "../../devel/hs-hls-retrie-plugin/buildlink3.mk"
.include "../../devel/hs-hls-hlint-plugin/buildlink3.mk"
.include "../../devel/hs-hls-module-name-plugin/buildlink3.mk"
.include "../../devel/hs-hls-pragmas-plugin/buildlink3.mk"
.include "../../devel/hs-hls-splice-plugin/buildlink3.mk"
.include "../../devel/hs-hls-alternate-number-format-plugin/buildlink3.mk"
.include "../../devel/hs-hls-qualify-imported-names-plugin/buildlink3.mk"
.include "../../devel/hs-hls-code-range-plugin/buildlink3.mk"
.include "../../devel/hs-hls-gadt-plugin/buildlink3.mk"
.include "../../devel/hs-hls-explicit-fixity-plugin/buildlink3.mk"
.include "../../devel/hs-hls-explicit-record-fields-plugin/buildlink3.mk"
.include "../../devel/hs-hls-fourmolu-plugin/buildlink3.mk"
.include "../../devel/hs-hls-refactor-plugin/buildlink3.mk"
.endif	# HASKELL_LANGUAGE_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-haskell-language-server
