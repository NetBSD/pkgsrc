# $NetBSD: buildlink3.mk,v 1.2 2022/01/18 15:20:29 tnn Exp $

BUILDLINK_TREE+=	spdlog

.if !defined(SPDLOG_BUILDLINK3_MK)
SPDLOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spdlog+=	spdlog>=1.8.5nb1
BUILDLINK_PKGSRCDIR.spdlog?=	../../devel/spdlog
.endif	# SPDLOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-spdlog
