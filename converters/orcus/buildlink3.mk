# $NetBSD: buildlink3.mk,v 1.6 2018/02/03 00:04:10 ryoon Exp $

BUILDLINK_TREE+=	orcus

.if !defined(ORCUS_BUILDLINK3_MK)
ORCUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.orcus+=	orcus>=0.13.2
BUILDLINK_PKGSRCDIR.orcus?=	../../converters/orcus

.endif	# ORCUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-orcus
