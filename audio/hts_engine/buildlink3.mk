# $NetBSD: buildlink3.mk,v 1.1 2020/06/22 00:52:42 ryoon Exp $

BUILDLINK_TREE+=	hts_engine_API

.if !defined(HTS_ENGINE_API_BUILDLINK3_MK)
HTS_ENGINE_API_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hts_engine_API+=	hts_engine_API>=1.10
BUILDLINK_PKGSRCDIR.hts_engine_API?=	../../audio/hts_engine
.endif	# HTS_ENGINE_API_BUILDLINK3_MK

BUILDLINK_TREE+=	-hts_engine_API
