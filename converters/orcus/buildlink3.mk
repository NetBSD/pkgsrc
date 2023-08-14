# $NetBSD: buildlink3.mk,v 1.11 2023/08/14 05:23:58 wiz Exp $

BUILDLINK_TREE+=	orcus

.if !defined(ORCUS_BUILDLINK3_MK)
ORCUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.orcus+=	orcus>=0.17.0
BUILDLINK_ABI_DEPENDS.orcus?=	orcus>=0.17.2nb3
BUILDLINK_PKGSRCDIR.orcus?=	../../converters/orcus

.endif	# ORCUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-orcus
