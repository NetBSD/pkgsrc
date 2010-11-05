# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/11/05 23:56:49 minskim Exp $

BUILDLINK_TREE+=	ptexenc

.if !defined(PTEXENC_BUILDLINK3_MK)
PTEXENC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ptexenc+=	ptexenc>=1.1.1
BUILDLINK_PKGSRCDIR.ptexenc?=	../../print/ptexenc

.include "../../print/kpathsea/buildlink3.mk"
.endif	# PTEXENC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ptexenc
