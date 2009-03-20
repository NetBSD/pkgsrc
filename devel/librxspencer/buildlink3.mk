# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:22 joerg Exp $

BUILDLINK_TREE+=	librxspencer

.if !defined(LIBRXSPENCER_BUILDLINK3_MK)
LIBRXSPENCER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librxspencer+=	librxspencer>=3.8.3
BUILDLINK_PKGSRCDIR.librxspencer?=	../../devel/librxspencer
BUILDLINK_INCDIRS.librxspencer+=	include/rxspencer
.endif # LIBRXSPENCER_BUILDLINK3_MK

BUILDLINK_TREE+=	-librxspencer
