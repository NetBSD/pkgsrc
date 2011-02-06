# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/02/06 05:55:15 schnoebe Exp $

BUILDLINK_TREE+=	poco

.if !defined(POCO_BUILDLINK3_MK)
POCO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco+=	poco>=1.3.5
BUILDLINK_ABI_DEPENDS.poco?=	poco>=1.3.5nb1
BUILDLINK_PKGSRCDIR.poco?=	../../wip/poco

.include "../../security/openssl/buildlink3.mk"
.endif # POCO_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco
