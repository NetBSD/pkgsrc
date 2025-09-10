# $NetBSD: buildlink3.mk,v 1.2 2025/09/10 10:34:02 vins Exp $

BUILDLINK_TREE+=	libasr

.if !defined(LIBASR_BUILDLINK3_MK)
LIBASR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libasr+=	libasr>=20240904
BUILDLINK_PKGSRCDIR.libasr?=	../../net/libasr
.endif	# LIBASR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libasr
