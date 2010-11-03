# $NetBSD: buildlink3.mk,v 1.2 2010/11/03 14:21:49 adam Exp $

BUILDLINK_TREE+=	xz

.if !defined(XZ_BUILDLINK3_MK)
XZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xz+=	xz>=5.0.0
BUILDLINK_PKGSRCDIR.xz?=	../../archivers/xz

.endif	# XZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-xz
