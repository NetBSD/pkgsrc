# $NetBSD: buildlink3.mk,v 1.20 2020/03/08 16:47:25 wiz Exp $

BUILDLINK_TREE+=	gnome-speech

.if !defined(GNOME_SPEECH_BUILDLINK3_MK)
GNOME_SPEECH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-speech+=	gnome-speech>=0.3.2
BUILDLINK_ABI_DEPENDS.gnome-speech+=	gnome-speech>=0.4.25nb7
BUILDLINK_PKGSRCDIR.gnome-speech?=	../../audio/gnome-speech

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.endif # GNOME_SPEECH_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-speech
