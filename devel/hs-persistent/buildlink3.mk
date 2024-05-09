# $NetBSD: buildlink3.mk,v 1.4 2024/05/09 01:32:07 pho Exp $

BUILDLINK_TREE+=	hs-persistent

.if !defined(HS_PERSISTENT_BUILDLINK3_MK)
HS_PERSISTENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-persistent+=	hs-persistent>=2.14.6
BUILDLINK_ABI_DEPENDS.hs-persistent+=	hs-persistent>=2.14.6.1nb1
BUILDLINK_PKGSRCDIR.hs-persistent?=	../../devel/hs-persistent

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../textproc/hs-attoparsec-aeson/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../sysutils/hs-fast-logger/buildlink3.mk"
.include "../../www/hs-http-api-data/buildlink3.mk"
.include "../../devel/hs-lift-type/buildlink3.mk"
.include "../../devel/hs-monad-logger/buildlink3.mk"
.include "../../www/hs-path-pieces/buildlink3.mk"
.include "../../devel/hs-resource-pool/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-silently/buildlink3.mk"
.include "../../devel/hs-th-lift-instances/buildlink3.mk"
.include "../../devel/hs-unliftio/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vault/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_PERSISTENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-persistent
