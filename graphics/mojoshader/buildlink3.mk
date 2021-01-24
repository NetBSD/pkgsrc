# $NetBSD: buildlink3.mk,v 1.1 2021/01/24 18:59:47 maya Exp $

BUILDLINK_TREE+=	mojoshader

.if !defined(MOJOSHADER_BUILDLINK3_MK)
MOJOSHADER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mojoshader+=	mojoshader>=0.0.20210110
BUILDLINK_PKGSRCDIR.mojoshader?=	../../graphics/mojoshader

.endif	# MOJOSHADER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mojoshader
