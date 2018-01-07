# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:22 rillig Exp $

BUILDLINK_TREE+=	crfsuite

.if !defined(CRFSUITE_BUILDLINK3_MK)
CRFSUITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.crfsuite+=	crfsuite>=0.12
BUILDLINK_PKGSRCDIR.crfsuite?=		../../math/crfsuite
.endif # CRFSUITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-crfsuite
