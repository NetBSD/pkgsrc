# $NetBSD: buildlink3.mk,v 1.1 2020/06/05 03:52:23 ryoon Exp $

BUILDLINK_TREE+=	mpv

.if !defined(MPV_BUILDLINK3_MK)
MPV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mpv+=	mpv>=0.32.0nb13
BUILDLINK_PKGSRCDIR.mpv?=	../../multimedia/mpv

.endif	# MPV_BUILDLINK3_MK

BUILDLINK_TREE+=	-mpv
