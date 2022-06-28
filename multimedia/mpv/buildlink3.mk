# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:34:56 wiz Exp $

BUILDLINK_TREE+=	mpv

.if !defined(MPV_BUILDLINK3_MK)
MPV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpv+=	mpv>=0.32.0nb13
BUILDLINK_ABI_DEPENDS.mpv?=	mpv>=0.34.1nb6
BUILDLINK_PKGSRCDIR.mpv?=	../../multimedia/mpv

.endif	# MPV_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpv
