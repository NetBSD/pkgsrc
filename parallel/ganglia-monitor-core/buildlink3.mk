# $NetBSD: buildlink3.mk,v 1.3 2023/08/14 05:25:05 wiz Exp $

BUILDLINK_TREE+=	ganglia-monitor-core

.if !defined(GANGLIA_MONITOR_CORE_BUILDLINK3_MK)
GANGLIA_MONITOR_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ganglia-monitor-core+=	ganglia-monitor-core>=3.7.2nb8
BUILDLINK_ABI_DEPENDS.ganglia-monitor-core?=	ganglia-monitor-core>=3.7.2nb24
BUILDLINK_PKGSRCDIR.ganglia-monitor-core?=	../../parallel/ganglia-monitor-core

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif	# GANGLIA_MONITOR_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ganglia-monitor-core
