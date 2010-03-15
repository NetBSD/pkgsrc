# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/03/15 19:40:44 pettai Exp $
#

BUILDLINK_TREE+=	opensaml

.if !defined(OPENSAML_BUILDLINK3_MK)
OPENSAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opensaml+=	opensaml>=2.3
BUILDLINK_ABI_DEPENDS.opensaml?=	opensaml>=2.3
BUILDLINK_PKGSRCDIR.opensaml?=	../../security/opensaml

.include "../../security/openssl/buildlink3.mk"
.endif	# OPENSAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-opensaml
