# $NetBSD: buildlink3.mk,v 1.22 2020/03/08 16:47:54 wiz Exp $

BUILDLINK_TREE+=	qalculate

.if !defined(QALCULATE_BUILDLINK3_MK)
QALCULATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qalculate+=	qalculate>=0.8.2
BUILDLINK_ABI_DEPENDS.qalculate+=	qalculate>=3.5.0nb3
BUILDLINK_PKGSRCDIR.qalculate?=		../../math/qalculate

.include "../../math/mpfr/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # QALCULATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qalculate
