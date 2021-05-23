# $NetBSD: buildlink3.mk,v 1.1 2021/05/23 07:15:24 ryoon Exp $

BUILDLINK_TREE+=	olm

.if !defined(OLM_BUILDLINK3_MK)
OLM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.olm+=	olm>=3.2.2
BUILDLINK_PKGSRCDIR.olm?=	../../security/olm
.endif	# OLM_BUILDLINK3_MK

BUILDLINK_TREE+=	-olm
