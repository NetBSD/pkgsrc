# $NetBSD: buildlink3.mk,v 1.1 2026/01/24 10:02:23 bsiegert Exp $

BUILDLINK_TREE+=	collectd

.if !defined(COLLECTD_BUILDLINK3_MK)
COLLECTD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.collectd+=	collectd>=5.12.0nb3
BUILDLINK_PKGSRCDIR.collectd?=	../../sysutils/collectd
.endif	# COLLECTD_BUILDLINK3_MK

BUILDLINK_TREE+=	-collectd
