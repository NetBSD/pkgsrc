# $NetBSD: buildlink3.mk,v 1.8 2025/04/21 21:10:48 perseant Exp $

BUILDLINK_TREE+=	opensaml

.if !defined(OPENSAML_BUILDLINK3_MK)
OPENSAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opensaml+=	opensaml>=2.3
BUILDLINK_ABI_DEPENDS.opensaml+=	opensaml>=3.3.1
BUILDLINK_PKGSRCDIR.opensaml?=		../../security/opensaml

.include "../../security/openssl/buildlink3.mk"
.endif	# OPENSAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-opensaml
