# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:23:54 joerg Exp $

BUILDLINK_TREE+=	lame

.if !defined(LAME_BUILDLINK3_MK)
LAME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lame+=	lame>=3.93.1nb2
BUILDLINK_ABI_DEPENDS.lame+=	lame>=3.96.1nb4
BUILDLINK_PKGSRCDIR.lame?=	../../audio/lame
.endif # LAME_BUILDLINK3_MK

BUILDLINK_TREE+=	-lame
