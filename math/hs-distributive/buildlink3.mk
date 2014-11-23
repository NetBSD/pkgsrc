# $NetBSD: buildlink3.mk,v 1.3 2014/11/23 12:52:33 szptvlfn Exp $

BUILDLINK_TREE+=	hs-distributive

.if !defined(HS_DISTRIBUTIVE_BUILDLINK3_MK)
HS_DISTRIBUTIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-distributive+=	hs-distributive>=0.4.4
BUILDLINK_ABI_DEPENDS.hs-distributive+=	hs-distributive>=0.4.4nb1
BUILDLINK_PKGSRCDIR.hs-distributive?=	../../math/hs-distributive

.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_DISTRIBUTIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-distributive
