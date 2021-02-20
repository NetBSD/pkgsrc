# $NetBSD: buildlink3.mk,v 1.2 2021/02/20 13:56:07 ryoon Exp $
#

BUILDLINK_TREE+=	opencc

.if !defined(OPENCC_BUILDLINK3_MK)
OPENCC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencc+=	opencc>=1.1.1
BUILDLINK_PKGSRCDIR.opencc?=	../../converters/opencc
.endif	# OPENCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencc
