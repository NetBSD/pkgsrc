# $NetBSD: buildlink3.mk,v 1.3 2013/02/06 23:21:00 jperkin Exp $

BUILDLINK_TREE+=	opensaml

.if !defined(OPENSAML_BUILDLINK3_MK)
OPENSAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opensaml+=	opensaml>=2.3
BUILDLINK_ABI_DEPENDS.opensaml+=	opensaml>=2.4.3nb2
BUILDLINK_PKGSRCDIR.opensaml?=		../../security/opensaml

.include "../../security/openssl/buildlink3.mk"
.endif	# OPENSAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-opensaml
