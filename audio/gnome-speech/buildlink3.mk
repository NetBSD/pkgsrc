# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:23:53 joerg Exp $

BUILDLINK_TREE+=	gnome-speech

.if !defined(GNOME_SPEECH_BUILDLINK3_MK)
GNOME_SPEECH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-speech+=	gnome-speech>=0.3.2
BUILDLINK_ABI_DEPENDS.gnome-speech+=	gnome-speech>=0.3.9nb2
BUILDLINK_PKGSRCDIR.gnome-speech?=	../../audio/gnome-speech

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.endif # GNOME_SPEECH_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-speech
