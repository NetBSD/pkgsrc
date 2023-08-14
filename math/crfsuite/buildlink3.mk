# $NetBSD: buildlink3.mk,v 1.3 2023/08/14 05:24:49 wiz Exp $

BUILDLINK_TREE+=	crfsuite

.if !defined(CRFSUITE_BUILDLINK3_MK)
CRFSUITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.crfsuite+=	crfsuite>=0.12
BUILDLINK_ABI_DEPENDS.crfsuite?=		crfsuite>=0.12nb5
BUILDLINK_PKGSRCDIR.crfsuite?=		../../math/crfsuite
.endif # CRFSUITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-crfsuite
