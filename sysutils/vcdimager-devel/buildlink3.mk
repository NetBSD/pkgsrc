# $NetBSD: buildlink3.mk,v 1.10 2011/04/22 13:42:06 obache Exp $

BUILDLINK_TREE+=	vcdimager

.if !defined(VCDIMAGER_BUILDLINK3_MK)
VCDIMAGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vcdimager+=	vcdimager>=0.7.20
BUILDLINK_ABI_DEPENDS.vcdimager+=	vcdimager>=0.7.23nb4
BUILDLINK_PKGSRCDIR.vcdimager?=	../../sysutils/vcdimager-devel

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # VCDIMAGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-vcdimager
