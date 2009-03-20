# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:08 joerg Exp $

BUILDLINK_TREE+=	howl

.if !defined(HOWL_BUILDLINK3_MK)
HOWL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.howl+=	howl>=0.9.5
BUILDLINK_ABI_DEPENDS.howl+=	howl>=0.9.5nb1
BUILDLINK_PKGSRCDIR.howl?=	../../net/howl
.endif # HOWL_BUILDLINK3_MK

BUILDLINK_TREE+=	-howl
