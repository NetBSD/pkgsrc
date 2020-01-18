# $NetBSD: buildlink3.mk,v 1.2 2020/01/18 21:48:26 jperkin Exp $

BUILDLINK_TREE+=	cjose

.if !defined(CJOSE_BUILDLINK3_MK)
CJOSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cjose+=	cjose>=0.6.1
BUILDLINK_ABI_DEPENDS.cjose?=	cjose>=0.6.1nb1
BUILDLINK_PKGSRCDIR.cjose?=	../../textproc/cjose

.include "../../textproc/jansson/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# CJOSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-cjose
