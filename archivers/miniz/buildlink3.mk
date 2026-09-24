# $NetBSD: buildlink3.mk,v 1.1 2026/09/24 16:12:48 ktnb Exp $

BUILDLINK_TREE+=	miniz

.if !defined(MINIZ_BUILDLINK3_MK)
MINIZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.miniz+=	miniz>=3.1.2
BUILDLINK_PKGSRCDIR.miniz?=	../../archivers/miniz

.endif	# MINIZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-miniz
