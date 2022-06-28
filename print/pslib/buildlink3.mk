# $NetBSD: buildlink3.mk,v 1.11 2022/06/28 11:35:30 wiz Exp $

BUILDLINK_TREE+=	pslib

.if !defined(PSLIB_BUILDLINK3_MK)
PSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pslib+=	pslib>=0.2.6
BUILDLINK_ABI_DEPENDS.pslib+=	pslib>=0.4.5nb8
BUILDLINK_PKGSRCDIR.pslib?=	../../print/pslib
.endif # PSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pslib
