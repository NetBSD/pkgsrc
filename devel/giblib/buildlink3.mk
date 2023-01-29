# $NetBSD: buildlink3.mk,v 1.23 2023/01/29 21:14:26 ryoon Exp $

BUILDLINK_TREE+=	giblib

.if !defined(GIBLIB_BUILDLINK3_MK)
GIBLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.giblib+=	giblib>=1.2.3nb3
BUILDLINK_ABI_DEPENDS.giblib+=	giblib>=1.2.4nb18
BUILDLINK_PKGSRCDIR.giblib?=	../../devel/giblib

.include "../../graphics/imlib2/buildlink3.mk"
.endif # GIBLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-giblib
