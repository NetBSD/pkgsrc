# $NetBSD: buildlink3.mk,v 1.1 2012/09/16 14:17:20 ryoon Exp $

BUILDLINK_TREE+=	opus

.if !defined(OPUS_BUILDLINK3_MK)
OPUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opus+=	opus>=1.0.1
BUILDLINK_PKGSRCDIR.opus?=	../../audio/libopus
.endif	# OPUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-opus
