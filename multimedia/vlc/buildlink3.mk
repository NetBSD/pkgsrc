# $NetBSD: buildlink3.mk,v 1.48 2022/06/28 11:34:57 wiz Exp $

BUILDLINK_TREE+=	vlc

.if !defined(VLC_BUILDLINK3_MK)
VLC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vlc+=	vlc>=3.0.1
BUILDLINK_ABI_DEPENDS.vlc?=	vlc>=3.0.17.4nb1
BUILDLINK_PKGSRCDIR.vlc?=	../../multimedia/vlc

.endif	# VLC_BUILDLINK3_MK

BUILDLINK_TREE+=	-vlc
