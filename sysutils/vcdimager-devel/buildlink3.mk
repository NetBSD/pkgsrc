# $NetBSD: buildlink3.mk,v 1.13 2018/01/07 13:04:32 rillig Exp $

BUILDLINK_TREE+=	vcdimager

.if !defined(VCDIMAGER_BUILDLINK3_MK)
VCDIMAGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vcdimager+=	vcdimager>=0.7.20
BUILDLINK_ABI_DEPENDS.vcdimager+=	vcdimager>=0.7.24nb2
BUILDLINK_PKGSRCDIR.vcdimager?=		../../sysutils/vcdimager-devel

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # VCDIMAGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-vcdimager
