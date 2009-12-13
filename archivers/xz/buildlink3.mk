# $NetBSD: buildlink3.mk,v 1.1 2009/12/13 13:26:17 wiz Exp $

BUILDLINK_TREE+=	xz

.if !defined(XZ_BUILDLINK3_MK)
XZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xz+=	xz>=4.999.9beta
BUILDLINK_PKGSRCDIR.xz?=	../../archivers/xz

.endif	# XZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-xz
