# $NetBSD: buildlink3.mk,v 1.10 2022/02/05 04:14:31 ryoon Exp $

BUILDLINK_TREE+=	orcus

.if !defined(ORCUS_BUILDLINK3_MK)
ORCUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.orcus+=	orcus>=0.17.0
BUILDLINK_PKGSRCDIR.orcus?=	../../converters/orcus

.endif	# ORCUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-orcus
