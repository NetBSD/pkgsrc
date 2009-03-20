# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:25 joerg Exp $

BUILDLINK_TREE+=	newt

.if !defined(NEWT_BUILDLINK3_MK)
NEWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.newt+=	newt>=0.51.6
BUILDLINK_ABI_DEPENDS.newt?=	newt>=0.51.6nb2
BUILDLINK_PKGSRCDIR.newt?=	../../devel/newt

.include "../../devel/libslang/buildlink3.mk"
.endif # NEWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-newt
