# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:23:59 joerg Exp $

BUILDLINK_TREE+=	wavpack

.if !defined(WAVPACK_BUILDLINK3_MK)
WAVPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wavpack+=	wavpack>=4.41.0
BUILDLINK_PKGSRCDIR.wavpack?=	../../audio/wavpack
.endif # WAVPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-wavpack
