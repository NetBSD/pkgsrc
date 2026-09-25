# $NetBSD: buildlink3.mk,v 1.1 2026/09/25 13:30:30 drixter Exp $

BUILDLINK_TREE+=	bgpdump

.if !defined(BGPDUMP_BUILDLINK3_MK)
BGPDUMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bgpdump+=	bgpdump>=1.6.2
BUILDLINK_PKGSRCDIR.bgpdump?=	../../net/bgpdump
.endif	# BGPDUMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-bgpdump
