# $NetBSD: buildlink3.mk,v 1.1 2015/01/17 00:16:12 wiz Exp $

BUILDLINK_TREE+=	speexdsp

.if !defined(SPEEXDSP_BUILDLINK3_MK)
SPEEXDSP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.speexdsp+=	speexdsp>=1.2rc3
BUILDLINK_PKGSRCDIR.speexdsp?=	../../audio/speexdsp

.include "../../audio/speex/buildlink3.mk"
.endif	# SPEEXDSP_BUILDLINK3_MK

BUILDLINK_TREE+=	-speexdsp
