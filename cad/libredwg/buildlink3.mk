# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:31:01 wiz Exp $
#

BUILDLINK_TREE+=	libredwg

.if !defined(LIBREDWG_BUILDLINK3_MK)
LIBREDWG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libredwg+=	libredwg>=0.12
BUILDLINK_ABI_DEPENDS.libredwg?=		libredwg>=0.12.4nb2
BUILDLINK_PKGSRCDIR.libredwg?=		../../cad/libredwg

.endif	# LIBREDWG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libredwg
