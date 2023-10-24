# $NetBSD: buildlink3.mk,v 1.3 2023/10/24 22:11:17 wiz Exp $

BUILDLINK_TREE+=	cjose

.if !defined(CJOSE_BUILDLINK3_MK)
CJOSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cjose+=	cjose>=0.6.1
BUILDLINK_ABI_DEPENDS.cjose?=	cjose>=0.6.2.2nb1
BUILDLINK_PKGSRCDIR.cjose?=	../../textproc/cjose

.include "../../textproc/jansson/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# CJOSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-cjose
