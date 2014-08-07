# $NetBSD: buildlink3.mk,v 1.1 2014/08/07 20:23:27 wiz Exp $

BUILDLINK_TREE+=	soundtouch

.if !defined(SOUNDTOUCH_BUILDLINK3_MK)
SOUNDTOUCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.soundtouch+=	soundtouch>=1.8.0
BUILDLINK_PKGSRCDIR.soundtouch?=	../../audio/soundtouch
.endif	# SOUNDTOUCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-soundtouch
