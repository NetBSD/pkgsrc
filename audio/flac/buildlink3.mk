# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:23:53 joerg Exp $

BUILDLINK_TREE+=	flac

.if !defined(FLAC_BUILDLINK3_MK)
FLAC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flac+=	flac>=1.1.0nb1
BUILDLINK_ABI_DEPENDS.flac+=	flac>=1.1.3nb1
BUILDLINK_PKGSRCDIR.flac?=	../../audio/flac

.include "../../multimedia/libogg/buildlink3.mk"
.endif # FLAC_BUILDLINK3_MK

BUILDLINK_TREE+=	-flac
