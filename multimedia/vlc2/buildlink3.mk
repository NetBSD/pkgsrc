# $NetBSD: buildlink3.mk,v 1.3 2018/04/25 22:39:02 kamil Exp $

BUILDLINK_TREE+=	vlc2

.if !defined(VLC2_BUILDLINK3_MK)
VLC2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vlc2+=	vlc2>=2.2
BUILDLINK_PKGSRCDIR.vlc2?=	../../multimedia/vlc2

.endif	# VLC2_BUILDLINK3_MK

BUILDLINK_TREE+=	-vlc2
