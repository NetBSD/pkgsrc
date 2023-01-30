# $NetBSD: buildlink3.mk,v 1.1 2023/01/30 19:38:06 nikita Exp $

BUILDLINK_TREE+=	jose

.if !defined(JOSE_BUILDLINK3_MK)
JOSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jose+=	jose>=11
BUILDLINK_ABI_DEPENDS.jose+=	jose>=11
BUILDLINK_PKGSRCDIR.jose?=	../../textproc/jose

.include "../../textproc/jansson/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# JOSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-jose
