# $NetBSD: buildlink3.mk,v 1.14 2009/03/20 19:23:54 joerg Exp $

BUILDLINK_TREE+=	audiofile

.if !defined(AUDIOFILE_BUILDLINK3_MK)
AUDIOFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.audiofile+=	libaudiofile>=0.2.1
BUILDLINK_ABI_DEPENDS.audiofile+=	libaudiofile>=0.2.6nb1
BUILDLINK_PKGSRCDIR.audiofile?=	../../audio/libaudiofile
.endif # AUDIOFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-audiofile
