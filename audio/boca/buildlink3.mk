# $NetBSD: buildlink3.mk,v 1.5 2025/12/26 11:12:06 adam Exp $

BUILDLINK_TREE+=	boca

.if !defined(BOCA_BUILDLINK3_MK)
BOCA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.boca+=	boca>=1.0.7
BUILDLINK_ABI_DEPENDS.boca?=	boca>=1.0.7nb4
BUILDLINK_PKGSRCDIR.boca?=	../../audio/boca

.include "../../devel/smooth/buildlink3.mk"
.include "../../misc/libcdio-paranoia/buildlink3.mk"
.include "../../textproc/uriparser/buildlink3.mk"
.endif	# BOCA_BUILDLINK3_MK

BUILDLINK_TREE+=	-boca
