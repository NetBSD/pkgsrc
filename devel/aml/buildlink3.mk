# $NetBSD: buildlink3.mk,v 1.1 2026/04/15 08:01:12 kikadf Exp $

BUILDLINK_TREE+=	aml

.if !defined(AML_BUILDLINK3_MK)
AML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aml+=	aml>=1.0.0
BUILDLINK_PKGSRCDIR.aml?=	../../devel/aml
.endif	# AML_BUILDLINK3_MK

BUILDLINK_TREE+=	-aml
