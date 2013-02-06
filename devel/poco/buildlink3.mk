# $NetBSD: buildlink3.mk,v 1.4 2013/02/06 23:21:03 jperkin Exp $

BUILDLINK_TREE+=	poco

.if !defined(POCO_BUILDLINK3_MK)
POCO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poco+=	poco>=1.3.5
BUILDLINK_ABI_DEPENDS.poco+=	poco>=1.4.2p1nb3
BUILDLINK_PKGSRCDIR.poco?=	../../devel/poco

.include "../../security/openssl/buildlink3.mk"
.endif # POCO_BUILDLINK3_MK

BUILDLINK_TREE+=	-poco
