# $NetBSD: buildlink3.mk,v 1.4 2014/02/12 23:18:34 tron Exp $

BUILDLINK_TREE+=	opensaml

.if !defined(OPENSAML_BUILDLINK3_MK)
OPENSAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opensaml+=	opensaml>=2.3
BUILDLINK_ABI_DEPENDS.opensaml+=	opensaml>=2.5.3nb3
BUILDLINK_PKGSRCDIR.opensaml?=		../../security/opensaml

.include "../../security/openssl/buildlink3.mk"
.endif	# OPENSAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-opensaml
