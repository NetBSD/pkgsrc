# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:27 joerg Exp $

BUILDLINK_TREE+=	pth

.if !defined(PTH_BUILDLINK3_MK)
PTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pth+=		pth>=2.0.0
BUILDLINK_ABI_DEPENDS.pth+=	pth>=2.0.0nb2
BUILDLINK_PKGSRCDIR.pth?=	../../devel/pth
.endif # PTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-pth
