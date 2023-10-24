# $NetBSD: buildlink3.mk,v 1.6 2023/10/24 22:10:04 wiz Exp $

BUILDLINK_TREE+=	rhash

.if !defined(RHASH_BUILDLINK3_MK)
RHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rhash+=	rhash>=1.3.1
BUILDLINK_ABI_DEPENDS.rhash+=	rhash>=1.4.4nb1
BUILDLINK_PKGSRCDIR.rhash?=	../../misc/rhash

.include "../../security/openssl/buildlink3.mk"
.endif	# RHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-rhash
