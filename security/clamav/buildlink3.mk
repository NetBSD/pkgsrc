# $NetBSD: buildlink3.mk,v 1.5 2017/01/05 11:27:21 roy Exp $

BUILDLINK_TREE+=	clamav

.if !defined(CLAMAV_BUILDLINK3_MK)
CLAMAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clamav+=	clamav>=0.95.3nb1
BUILDLINK_ABI_DEPENDS.clamav+=	clamav>=0.98.7nb2
BUILDLINK_PKGSRCDIR.clamav?=	../../security/clamav
.endif	# CLAMAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-clamav
