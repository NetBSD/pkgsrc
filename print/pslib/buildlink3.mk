# $NetBSD: buildlink3.mk,v 1.10 2012/05/07 01:53:55 dholland Exp $

BUILDLINK_TREE+=	pslib

.if !defined(PSLIB_BUILDLINK3_MK)
PSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pslib+=	pslib>=0.2.6
BUILDLINK_ABI_DEPENDS.pslib+=	pslib>=0.2.6nb3
BUILDLINK_PKGSRCDIR.pslib?=	../../print/pslib
.endif # PSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pslib
