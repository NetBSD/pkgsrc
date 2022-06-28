# $NetBSD: buildlink3.mk,v 1.8 2022/06/28 11:36:08 wiz Exp $

BUILDLINK_TREE+=	btparse

.if !defined(BTPARSE_BUILDLINK3_MK)
BTPARSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.btparse+=	btparse>=0.34
BUILDLINK_ABI_DEPENDS.btparse?=	btparse>=0.35nb10
BUILDLINK_PKGSRCDIR.btparse?=	../../textproc/btparse
.endif # BTPARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-btparse
