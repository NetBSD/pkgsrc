# $NetBSD: buildlink3.mk,v 1.12 2026/09/27 11:34:49 tnn Exp $

BUILDLINK_TREE+=	boca

.if !defined(BOCA_BUILDLINK3_MK)
BOCA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.boca+=	boca>=1.0.7
BUILDLINK_ABI_DEPENDS.boca?=	boca>=1.0.7nb11
BUILDLINK_PKGSRCDIR.boca?=	../../audio/boca

.include "../../devel/smooth/buildlink3.mk"
.include "../../misc/libcdio-paranoia/buildlink3.mk"
.include "../../textproc/uriparser/buildlink3.mk"
.endif	# BOCA_BUILDLINK3_MK

BUILDLINK_TREE+=	-boca
