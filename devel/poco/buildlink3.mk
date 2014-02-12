# $NetBSD: buildlink3.mk,v 1.5 2014/02/12 23:17:49 tron Exp $

BUILDLINK_TREE+=	poco

.if !defined(POCO_BUILDLINK3_MK)
POCO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco+=	poco>=1.3.5
BUILDLINK_ABI_DEPENDS.poco+=	poco>=1.4.2p1nb4
BUILDLINK_PKGSRCDIR.poco?=	../../devel/poco

.include "../../security/openssl/buildlink3.mk"
.endif # POCO_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco
