# $NetBSD: buildlink3.mk,v 1.1 2026/10/14 03:53:35 agc Exp $
BUILDLINK_TREE+=	libagcre

.if !defined(LIBAGCRE_BUILDLINK3_MK)
LIBAGCRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libagcre+=	libagcre>=20261013
BUILDLINK_PKGSRCDIR.libagcre?=	../../devel/libagcre
.endif	# LIBAGCRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libagcre
