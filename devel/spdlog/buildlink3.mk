# $NetBSD: buildlink3.mk,v 1.1 2020/02/05 13:32:27 ryoon Exp $

BUILDLINK_TREE+=	spdlog

.if !defined(SPDLOG_BUILDLINK3_MK)
SPDLOG_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.spdlog?=	build

BUILDLINK_API_DEPENDS.spdlog+=	spdlog>=1.5.0
BUILDLINK_PKGSRCDIR.spdlog?=	../../devel/spdlog
.endif	# SPDLOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-spdlog
