# $NetBSD: buildlink3.mk,v 1.9 2023/01/27 08:50:18 pho Exp $

BUILDLINK_TREE+=	hs-shakespeare

.if !defined(HS_SHAKESPEARE_BUILDLINK3_MK)
HS_SHAKESPEARE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-shakespeare+=	hs-shakespeare>=2.0.30
BUILDLINK_ABI_DEPENDS.hs-shakespeare+=	hs-shakespeare>=2.0.30
BUILDLINK_PKGSRCDIR.hs-shakespeare?=	../../textproc/hs-shakespeare

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-th-lift/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_SHAKESPEARE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-shakespeare
