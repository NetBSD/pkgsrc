# $NetBSD: buildlink3.mk,v 1.3 2023/08/14 05:24:56 wiz Exp $

BUILDLINK_TREE+=	mpv

.if !defined(MPV_BUILDLINK3_MK)
MPV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpv+=	mpv>=0.32.0nb13
BUILDLINK_ABI_DEPENDS.mpv?=	mpv>=0.35.1nb6
BUILDLINK_PKGSRCDIR.mpv?=	../../multimedia/mpv

.endif	# MPV_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpv
