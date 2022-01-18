# $NetBSD: buildlink3.mk,v 1.2 2022/01/18 02:48:19 pho Exp $

BUILDLINK_TREE+=	hoogle

.if !defined(HOOGLE_BUILDLINK3_MK)
HOOGLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hoogle+=	hoogle>=5.0.18
BUILDLINK_ABI_DEPENDS.hoogle+=	hoogle>=5.0.18.1nb1
BUILDLINK_PKGSRCDIR.hoogle?=	../../net/hoogle

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../net/hs-connection/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-foundation/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.include "../../www/hs-http-conduit/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../www/hs-js-flot/buildlink3.mk"
.include "../../www/hs-js-jquery/buildlink3.mk"
.include "../../devel/hs-mmap/buildlink3.mk"
.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../sysutils/hs-process-extras/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-storable-tuple/buildlink3.mk"
.include "../../archivers/hs-tar/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-wai-logger/buildlink3.mk"
.include "../../www/hs-warp/buildlink3.mk"
.include "../../www/hs-warp-tls/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.endif	# HOOGLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hoogle
