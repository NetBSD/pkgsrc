# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:13 joerg Exp $

BUILDLINK_TREE+=	ffcall

.if !defined(FFCALL_BUILDLINK3_MK)
FFCALL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffcall+=	ffcall>=1.9
BUILDLINK_ABI_DEPENDS.ffcall+=	ffcall>=1.10nb1
BUILDLINK_PKGSRCDIR.ffcall?=	../../devel/ffcall
.endif # FFCALL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffcall
