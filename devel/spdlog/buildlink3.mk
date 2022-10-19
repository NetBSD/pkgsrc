# $NetBSD: buildlink3.mk,v 1.3 2022/10/19 18:27:53 adam Exp $

BUILDLINK_TREE+=	spdlog

.if !defined(SPDLOG_BUILDLINK3_MK)
SPDLOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spdlog+=	spdlog>=1.8.5nb1
BUILDLINK_PKGSRCDIR.spdlog?=	../../devel/spdlog

.include "../../textproc/fmtlib/buildlink3.mk"
.endif	# SPDLOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-spdlog
