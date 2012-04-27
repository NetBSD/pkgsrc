# $NetBSD: buildlink3.mk,v 1.12 2012/04/27 12:31:51 obache Exp $

BUILDLINK_TREE+=	parrot

.if !defined(PARROT_BUILDLINK3_MK)
PARROT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.parrot+=		parrot>=0.4.0
BUILDLINK_ABI_DEPENDS.parrot?=		parrot>=4.1.0nb1
BUILDLINK_PKGSRCDIR.parrot?=		../../lang/parrot

.include "../../textproc/icu/buildlink3.mk"
.endif # PARROT_BUILDLINK3_MK

BUILDLINK_TREE+=	-parrot
