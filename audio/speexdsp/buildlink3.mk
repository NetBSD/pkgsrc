# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:03:56 rillig Exp $

BUILDLINK_TREE+=	speexdsp

.if !defined(SPEEXDSP_BUILDLINK3_MK)
SPEEXDSP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.speexdsp+=	speexdsp>=1.2rc3
BUILDLINK_PKGSRCDIR.speexdsp?=		../../audio/speexdsp

.include "../../audio/speex/buildlink3.mk"
.endif	# SPEEXDSP_BUILDLINK3_MK

BUILDLINK_TREE+=	-speexdsp
