# $NetBSD: buildlink3.mk,v 1.47 2019/07/02 20:52:12 nia Exp $

BUILDLINK_TREE+=	vlc

.if !defined(VLC_BUILDLINK3_MK)
VLC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vlc+=	vlc>=3.0.1
BUILDLINK_PKGSRCDIR.vlc?=	../../multimedia/vlc

.endif	# VLC_BUILDLINK3_MK

BUILDLINK_TREE+=	-vlc
