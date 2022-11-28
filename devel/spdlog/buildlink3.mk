# $NetBSD: buildlink3.mk,v 1.5 2022/11/28 14:38:53 nia Exp $

BUILDLINK_TREE+=	spdlog

.if !defined(SPDLOG_BUILDLINK3_MK)
SPDLOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spdlog+=	spdlog>=1.8.5nb1
BUILDLINK_PKGSRCDIR.spdlog?=	../../devel/spdlog

# Support the use of SPDLOG_FMT_EXTERNAL.
# Sometimes tweakme.h is not properly applied...
BUILDLINK_CPPFLAGS.spdlog+=	-DSPDLOG_FMT_EXTERNAL

.include "../../textproc/fmtlib/buildlink3.mk"
.endif	# SPDLOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-spdlog
