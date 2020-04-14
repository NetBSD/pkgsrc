# $NetBSD: buildlink3.mk,v 1.1 2020/04/14 14:13:10 ryoon Exp $

BUILDLINK_TREE+=	gom

.if !defined(GOM_BUILDLINK3_MK)
GOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gom+=	gom>=0.4
BUILDLINK_PKGSRCDIR.gom?=	../../databases/gom

.endif	# GOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gom
