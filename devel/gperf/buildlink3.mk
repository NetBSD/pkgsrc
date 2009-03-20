# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:15 joerg Exp $

BUILDLINK_TREE+=	gperf

.if !defined(GPERF_BUILDLINK3_MK)
GPERF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gperf+=	gperf>=3.0.1
BUILDLINK_PKGSRCDIR.gperf?=	../../devel/gperf
BUILDLINK_DEPMETHOD.gperf?=	build
.endif # GPERF_BUILDLINK3_MK

BUILDLINK_TREE+=	-gperf
