# $NetBSD: buildlink3.mk,v 1.2 2018/03/17 08:02:14 adam Exp $

BUILDLINK_TREE+=	rhash

.if !defined(RHASH_BUILDLINK3_MK)
RHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rhash+=	rhash>=1.3.1
BUILDLINK_PKGSRCDIR.rhash?=	../../misc/rhash

BUILDLINK_DEPMETHOD.rhash?=	build

.include "../../security/openssl/buildlink3.mk"
.endif	# RHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-rhash
