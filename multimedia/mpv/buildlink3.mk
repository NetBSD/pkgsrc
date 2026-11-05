# $NetBSD: buildlink3.mk,v 1.4 2026/11/05 22:27:04 leot Exp $

BUILDLINK_TREE+=	mpv

.if !defined(MPV_BUILDLINK3_MK)
MPV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpv+=	mpv>=0.32.0nb13
BUILDLINK_ABI_DEPENDS.mpv?=	mpv>=0.42.0
BUILDLINK_PKGSRCDIR.mpv?=	../../multimedia/mpv

.endif	# MPV_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpv
