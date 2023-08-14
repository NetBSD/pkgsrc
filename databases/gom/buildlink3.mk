# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:23:59 wiz Exp $

BUILDLINK_TREE+=	gom

.if !defined(GOM_BUILDLINK3_MK)
GOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gom+=	gom>=0.4
BUILDLINK_ABI_DEPENDS.gom?=	gom>=0.4nb11
BUILDLINK_PKGSRCDIR.gom?=	../../databases/gom

.endif	# GOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gom
