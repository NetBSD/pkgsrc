# $NetBSD: buildlink3.mk,v 1.22 2013/07/05 13:29:29 ryoon Exp $

BUILDLINK_TREE+=	giblib

.if !defined(GIBLIB_BUILDLINK3_MK)
GIBLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.giblib+=	giblib>=1.2.3nb3
BUILDLINK_ABI_DEPENDS.giblib+=	giblib>=1.2.4nb16
BUILDLINK_PKGSRCDIR.giblib?=	../../devel/giblib

.include "../../graphics/imlib2/buildlink3.mk"
.endif # GIBLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-giblib
