# $NetBSD: buildlink3.mk,v 1.2 2023/07/20 21:40:53 nia Exp $

BUILDLINK_TREE+=	prometheus-cpp

.if !defined(PROMETHEUS_CPP_BUILDLINK3_MK)
PROMETHEUS_CPP_BUILDLINK3_MK:=

USE_CXX_FEATURES+=		c++14

BUILDLINK_DEPMETHOD.prometheus-cpp?=	build

BUILDLINK_API_DEPENDS.prometheus-cpp+=	prometheus-cpp>=1.1.0
BUILDLINK_PKGSRCDIR.prometheus-cpp?=	../../databases/prometheus-cpp

.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# PROMETHEUS_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-prometheus-cpp
