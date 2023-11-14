# $NetBSD: buildlink3.mk,v 1.2 2023/11/14 16:32:51 nia Exp $

BUILDLINK_TREE+=	soundtouch

.if !defined(SOUNDTOUCH_BUILDLINK3_MK)
SOUNDTOUCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.soundtouch+=	soundtouch>=1.8.0
BUILDLINK_PKGSRCDIR.soundtouch?=	../../audio/soundtouch
BUILDLINK_INCDIRS.soundtouch+=		include/soundtouch
.endif	# SOUNDTOUCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-soundtouch
