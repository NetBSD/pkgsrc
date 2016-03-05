# $NetBSD: buildlink3.mk,v 1.5 2016/03/05 11:27:55 jperkin Exp $

BUILDLINK_TREE+=	opensaml

.if !defined(OPENSAML_BUILDLINK3_MK)
OPENSAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opensaml+=	opensaml>=2.3
BUILDLINK_ABI_DEPENDS.opensaml+=	opensaml>=2.5.3nb7
BUILDLINK_PKGSRCDIR.opensaml?=		../../security/opensaml

.include "../../security/openssl/buildlink3.mk"
.endif	# OPENSAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-opensaml
