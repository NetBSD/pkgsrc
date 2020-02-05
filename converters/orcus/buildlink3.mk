# $NetBSD: buildlink3.mk,v 1.8 2020/02/05 13:54:29 ryoon Exp $

BUILDLINK_TREE+=	orcus

.if !defined(ORCUS_BUILDLINK3_MK)
ORCUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.orcus+=	orcus>=0.15.3
BUILDLINK_PKGSRCDIR.orcus?=	../../converters/orcus

.endif	# ORCUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-orcus
