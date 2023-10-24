# $NetBSD: buildlink3.mk,v 1.7 2023/10/24 22:10:53 wiz Exp $

BUILDLINK_TREE+=	opensaml

.if !defined(OPENSAML_BUILDLINK3_MK)
OPENSAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opensaml+=	opensaml>=2.3
BUILDLINK_ABI_DEPENDS.opensaml+=	opensaml>=3.1.0nb10
BUILDLINK_PKGSRCDIR.opensaml?=		../../security/opensaml

.include "../../security/openssl/buildlink3.mk"
.endif	# OPENSAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-opensaml
