# $NetBSD: buildlink3.mk,v 1.9 2021/02/06 06:29:04 ryoon Exp $

BUILDLINK_TREE+=	orcus

.if !defined(ORCUS_BUILDLINK3_MK)
ORCUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.orcus+=	orcus>=0.16.1
BUILDLINK_PKGSRCDIR.orcus?=	../../converters/orcus

.endif	# ORCUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-orcus
