# $NetBSD: buildlink3.mk,v 1.1 2015/07/03 16:05:02 khorben Exp $

BUILDLINK_TREE+=	radare2

.if !defined(RADARE2_BUILDLINK3_MK)
RADARE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.radare2+=	radare2>=0.9.9
BUILDLINK_ABI_DEPENDS.radare2?=	radare2>=0.9.9
BUILDLINK_PKGSRCDIR.radare2?=	../../devel/radare2

.endif	# RADARE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-radare2
