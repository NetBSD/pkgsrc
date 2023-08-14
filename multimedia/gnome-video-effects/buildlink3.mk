# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:24:55 wiz Exp $

BUILDLINK_TREE+=	gnome-video-effects

.if !defined(GNOME_VIDEO_EFFECTS_BUILDLINK3_MK)
GNOME_VIDEO_EFFECTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-video-effects+=	gnome-video-effects>=0.5.0
BUILDLINK_ABI_DEPENDS.gnome-video-effects?=	gnome-video-effects>=0.5.0nb3
BUILDLINK_PKGSRCDIR.gnome-video-effects?=	../../multimedia/gnome-video-effects
.endif	# GNOME_VIDEO_EFFECTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-video-effects
