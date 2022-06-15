# $NetBSD: buildlink3.mk,v 1.5 2022/06/15 08:54:58 adam Exp $

BUILDLINK_TREE+=	rhash

.if !defined(RHASH_BUILDLINK3_MK)
RHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rhash+=	rhash>=1.3.1
BUILDLINK_ABI_DEPENDS.rhash+=	rhash>=1.3.9nb1
BUILDLINK_PKGSRCDIR.rhash?=	../../misc/rhash

.include "../../security/openssl/buildlink3.mk"
.endif	# RHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-rhash
