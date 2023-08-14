# $NetBSD: buildlink3.mk,v 1.8 2023/08/14 05:24:16 wiz Exp $

BUILDLINK_TREE+=	spdlog

.if !defined(SPDLOG_BUILDLINK3_MK)
SPDLOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spdlog+=	spdlog>=1.8.5nb1
BUILDLINK_ABI_DEPENDS.spdlog?=	spdlog>=1.12.0nb2
BUILDLINK_PKGSRCDIR.spdlog?=	../../devel/spdlog

# Support the use of SPDLOG_FMT_EXTERNAL.
# Sometimes tweakme.h is not properly applied...
BUILDLINK_CPPFLAGS.spdlog+=	-DSPDLOG_FMT_EXTERNAL

USE_CXX_FEATURES+=	c++11 put_time

.include "../../textproc/fmtlib/buildlink3.mk"
.endif	# SPDLOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-spdlog
