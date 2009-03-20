# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:10 joerg Exp $

BUILDLINK_TREE+=	buddy

.if !defined(BUDDY_BUILDLINK3_MK)
BUDDY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.buddy+=	buddy>=2.4
BUILDLINK_PKGSRCDIR.buddy?=	../../devel/buddy
.endif # BUDDY_BUILDLINK3_MK

BUILDLINK_TREE+=	-buddy
