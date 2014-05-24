# $NetBSD: buildlink3.mk,v 1.1 2014/05/24 10:21:13 obache Exp $

BUILDLINK_TREE+=	marisa

.if !defined(MARISA_BUILDLINK3_MK)
MARISA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marisa+=	marisa>=0.2.4
BUILDLINK_PKGSRCDIR.marisa?=	../../textproc/marisa
.endif	# MARISA_BUILDLINK3_MK

BUILDLINK_TREE+=	-marisa
