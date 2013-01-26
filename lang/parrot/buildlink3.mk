# $NetBSD: buildlink3.mk,v 1.14 2013/01/26 21:36:34 adam Exp $

BUILDLINK_TREE+=	parrot

.if !defined(PARROT_BUILDLINK3_MK)
PARROT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.parrot+=		parrot>=0.4.0
BUILDLINK_ABI_DEPENDS.parrot+=		parrot>=4.8.0nb2
BUILDLINK_PKGSRCDIR.parrot?=		../../lang/parrot

.include "../../textproc/icu/buildlink3.mk"
.endif # PARROT_BUILDLINK3_MK

BUILDLINK_TREE+=	-parrot
