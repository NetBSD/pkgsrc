# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:28 joerg Exp $

BUILDLINK_TREE+=	btparse

.if !defined(BTPARSE_BUILDLINK3_MK)
BTPARSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.btparse+=	btparse>=0.34
BUILDLINK_PKGSRCDIR.btparse?=	../../textproc/btparse
.endif # BTPARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-btparse
