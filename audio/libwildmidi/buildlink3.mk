# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/11/30 13:47:15 wiz Exp $

BUILDLINK_TREE+=	libwildmidi

.if !defined(LIBWILDMIDI_BUILDLINK3_MK)
LIBWILDMIDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwildmidi+=	libwildmidi>=0.2.3.4
BUILDLINK_PKGSRCDIR.libwildmidi?=	../../audio/libwildmidi
.endif	# LIBWILDMIDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwildmidi
