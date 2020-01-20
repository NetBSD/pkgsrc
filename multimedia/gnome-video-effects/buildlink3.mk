# $NetBSD: buildlink3.mk,v 1.1 2020/01/20 02:20:19 nia Exp $

BUILDLINK_TREE+=	gnome-video-effects

.if !defined(GNOME_VIDEO_EFFECTS_BUILDLINK3_MK)
GNOME_VIDEO_EFFECTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-video-effects+=	gnome-video-effects>=0.5.0
BUILDLINK_PKGSRCDIR.gnome-video-effects?=	../../multimedia/gnome-video-effects
.endif	# GNOME_VIDEO_EFFECTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-video-effects
