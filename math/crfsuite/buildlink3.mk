# $NetBSD: buildlink3.mk,v 1.1.1.1 2014/10/29 23:13:21 cheusov Exp $

BUILDLINK_TREE+=	crfsuite

.if !defined(CRFSUITE_BUILDLINK3_MK)
CRFSUITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.crfsuite+=	crfsuite>=0.12
BUILDLINK_PKGSRCDIR.crfsuite?=	../../math/crfsuite
.endif # CRFSUITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-crfsuite
