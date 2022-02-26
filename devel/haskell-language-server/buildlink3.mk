# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:57:46 pho Exp $

BUILDLINK_TREE+=	haskell-language-server

.if !defined(HASKELL_LANGUAGE_SERVER_BUILDLINK3_MK)
HASKELL_LANGUAGE_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.haskell-language-server+=	haskell-language-server>=1.6.1
BUILDLINK_ABI_DEPENDS.haskell-language-server+=	haskell-language-server>=1.6.1.1nb1
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
.include "../../sysutils/hs-hslogger/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-optparse-simple/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../databases/hs-sqlite-simple/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-hls-call-hierarchy-plugin/buildlink3.mk"
.include "../../devel/hs-hls-explicit-imports-plugin/buildlink3.mk"
.include "../../devel/hs-hls-refine-imports-plugin/buildlink3.mk"
.include "../../devel/hs-hls-module-name-plugin/buildlink3.mk"
.include "../../devel/hs-hls-pragmas-plugin/buildlink3.mk"
.include "../../devel/hs-hls-alternate-number-format-plugin/buildlink3.mk"
.include "../../devel/hs-hls-qualify-imported-names-plugin/buildlink3.mk"
.include "../../devel/hs-hls-selection-range-plugin/buildlink3.mk"
.include "../../devel/hs-hls-floskell-plugin/buildlink3.mk"
.include "../../devel/hs-hls-fourmolu-plugin/buildlink3.mk"
.include "../../devel/hs-hls-oumolu-plugin/buildlink3.mk"
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../devel/hs-gitrev/buildlink3.mk"
.endif	# HASKELL_LANGUAGE_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-haskell-language-server
