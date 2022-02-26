# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:57:56 pho Exp $

BUILDLINK_TREE+=	hs-ghcide

.if !defined(HS_GHCIDE_BUILDLINK3_MK)
HS_GHCIDE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ghcide+=	hs-ghcide>=1.6.0
BUILDLINK_ABI_DEPENDS.hs-ghcide+=	hs-ghcide>=1.6.0.0nb1
BUILDLINK_PKGSRCDIR.hs-ghcide?=		../../devel/hs-ghcide

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../security/hs-cryptohash-sha1/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-dependent-map/buildlink3.mk"
.include "../../devel/hs-dependent-sum/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-fingertree/buildlink3.mk"
.include "../../devel/hs-focus/buildlink3.mk"
.include "../../textproc/hs-fuzzy/buildlink3.mk"
.include "../../devel/hs-ghc-check/buildlink3.mk"
.include "../../devel/hs-ghc-exactprint/buildlink3.mk"
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../devel/hs-ghc-trace-events/buildlink3.mk"
.include "../../textproc/hs-Glob/buildlink3.mk"
.include "../../textproc/hs-haddock-library/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-hie-bios/buildlink3.mk"
.include "../../devel/hs-hie-compat/buildlink3.mk"
.include "../../devel/hs-hiedb/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../sysutils/hs-hslogger/buildlink3.mk"
.include "../../devel/hs-implicit-hie-cradle/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-list-t/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../math/hs-monoid-subclasses/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../sysutils/hs-opentelemetry/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-parallel/buildlink3.mk"
.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../textproc/hs-prettyprinter-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/retrie/buildlink3.mk"
.include "../../textproc/hs-rope-utf16-splay/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../devel/hs-sorted-list/buildlink3.mk"
.include "../../databases/hs-sqlite-simple/buildlink3.mk"
.include "../../devel/hs-stm-containers/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-unliftio/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-vector-algorithms/buildlink3.mk"
.include "../../devel/hs-gitrev/buildlink3.mk"
.include "../../devel/hs-heapsize/buildlink3.mk"
.endif	# HS_GHCIDE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ghcide
