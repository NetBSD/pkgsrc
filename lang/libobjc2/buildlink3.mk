# $NetBSD: buildlink3.mk,v 1.1 2020/04/16 17:35:47 joerg Exp $
#

BUILDLINK_TREE+=	libobjc2

.if !defined(LIBOBJC2_BUILDLINK3_MK)
LIBOBJC2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libobjc2+=	libobjc2>=2.0
BUILDLINK_ABI_DEPENDS.libobjc2+=	libobjc2>=2.0
BUILDLINK_PKGSRCDIR.libobjc2?=	../../lang/libobjc2
.endif # LIBOBJC2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libobjc2
