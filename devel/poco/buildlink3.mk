# $NetBSD: buildlink3.mk,v 1.9 2023/10/24 22:08:55 wiz Exp $

BUILDLINK_TREE+=	poco

.if !defined(POCO_BUILDLINK3_MK)
POCO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco+=	poco>=1.6.1
BUILDLINK_ABI_DEPENDS.poco+=	poco>=1.6.1nb4
BUILDLINK_PKGSRCDIR.poco?=	../../devel/poco

.include "../../security/openssl/buildlink3.mk"
.endif # POCO_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco
