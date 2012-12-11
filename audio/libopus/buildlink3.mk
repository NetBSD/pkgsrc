# $NetBSD: buildlink3.mk,v 1.2 2012/12/11 10:29:00 ryoon Exp $

BUILDLINK_TREE+=	opus

.if !defined(OPUS_BUILDLINK3_MK)
OPUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opus+=	opus>=1.0.1
BUILDLINK_ABI_DEPENDS.opus+=	opus>=1.0.2
BUILDLINK_PKGSRCDIR.opus?=	../../audio/libopus
.endif	# OPUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-opus
