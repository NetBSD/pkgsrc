# $NetBSD: buildlink3.mk,v 1.23 2012/10/08 23:00:48 adam Exp $

BUILDLINK_TREE+=	blib

.if !defined(BLIB_BUILDLINK3_MK)
BLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blib+=	blib>=1.0.2nb1
BUILDLINK_ABI_DEPENDS.blib+=	blib>=1.0.2nb19
BUILDLINK_PKGSRCDIR.blib?=	../../devel/blib

.include "../../x11/gtk2/buildlink3.mk"
.endif # BLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-blib
