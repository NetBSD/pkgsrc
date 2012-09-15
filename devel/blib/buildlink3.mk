# $NetBSD: buildlink3.mk,v 1.21 2012/09/15 10:04:06 obache Exp $

BUILDLINK_TREE+=	blib

.if !defined(BLIB_BUILDLINK3_MK)
BLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blib+=	blib>=1.0.2nb1
BUILDLINK_ABI_DEPENDS.blib+=	blib>=1.0.2nb17
BUILDLINK_PKGSRCDIR.blib?=	../../devel/blib

.include "../../x11/gtk2/buildlink3.mk"
.endif # BLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-blib
