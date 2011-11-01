# $NetBSD: buildlink3.mk,v 1.16 2011/11/01 06:00:55 sbd Exp $

BUILDLINK_TREE+=	giblib

.if !defined(GIBLIB_BUILDLINK3_MK)
GIBLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.giblib+=	giblib>=1.2.3nb3
BUILDLINK_ABI_DEPENDS.giblib+=	giblib>=1.2.4nb10
BUILDLINK_PKGSRCDIR.giblib?=	../../devel/giblib

.include "../../graphics/imlib2/buildlink3.mk"
.endif # GIBLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-giblib
