# $NetBSD: buildlink3.mk,v 1.1 2025/02/23 21:54:05 wiz Exp $

BUILDLINK_TREE+=	cpuinfo

.if !defined(CPUINFO_BUILDLINK3_MK)
CPUINFO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.cpuinfo?=	build

BUILDLINK_API_DEPENDS.cpuinfo+=	cpuinfo>=0.0.20250219
BUILDLINK_PKGSRCDIR.cpuinfo?=	../../sysutils/cpuinfo
.endif	# CPUINFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-cpuinfo
