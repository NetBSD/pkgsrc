# $NetBSD: buildlink3.mk,v 1.1 2019/03/16 08:03:56 bsiegert Exp $

BUILDLINK_TREE+=	cjose

.if !defined(CJOSE_BUILDLINK3_MK)
CJOSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cjose+=	cjose>=0.6.1
BUILDLINK_PKGSRCDIR.cjose?=	../../textproc/cjose

.include "../../textproc/jansson/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# CJOSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-cjose
