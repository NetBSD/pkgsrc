# $NetBSD: buildlink3.mk,v 1.1 2016/05/01 05:03:23 mef Exp $

BUILDLINK_TREE+=	libasr

.if !defined(LIBASR_BUILDLINK3_MK)
LIBASR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libasr+=	libasr>=1.0.2
BUILDLINK_PKGSRCDIR.libasr?=	../../net/libasr
.endif	# LIBASR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libasr
