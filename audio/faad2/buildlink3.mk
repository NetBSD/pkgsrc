# $NetBSD: buildlink3.mk,v 1.15 2023/11/13 15:22:45 wiz Exp $

BUILDLINK_TREE+=	faad2

.if !defined(FAAD2_BUILDLINK3_MK)
FAAD2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.faad2+=	faad2>=2.6.1
BUILDLINK_ABI_DEPENDS.faad2+=	faad2>=2.11.0
BUILDLINK_PKGSRCDIR.faad2?=	../../audio/faad2
.endif # FAAD2_BUILDLINK3_MK

BUILDLINK_TREE+=	-faad2
