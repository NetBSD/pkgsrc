# $NetBSD: buildlink3.mk,v 1.1 2021/04/02 21:32:59 plunky Exp $
#

BUILDLINK_TREE+=	libredwg

.if !defined(LIBREDWG_BUILDLINK3_MK)
LIBREDWG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libredwg+=	libredwg>=0.12
BUILDLINK_PKGSRCDIR.libredwg?=		../../cad/libredwg

.endif	# LIBREDWG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libredwg
