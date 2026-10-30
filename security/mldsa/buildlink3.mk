# $NetBSD: buildlink3.mk,v 1.1 2026/10/30 21:34:16 agc Exp $

BUILDLINK_TREE+=	libmldsa

.if !defined(LIBMLDSA_BUILDLINK3_MK)
LIBMLDSA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmldsa+=	libmldsa>=20261028
BUILDLINK_PKGSRCDIR.libmldsa?=		../../security/libmldsa
.endif	# LIBMLDSA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmldsa
