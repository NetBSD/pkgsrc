# $NetBSD: buildlink3.mk,v 1.8 2012/05/07 01:53:47 dholland Exp $

BUILDLINK_TREE+=	tasp-vsipl

.if !defined(TASP_VSIPL_BUILDLINK3_MK)
TASP_VSIPL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tasp-vsipl+=	tasp-vsipl>=20030710
BUILDLINK_ABI_DEPENDS.tasp-vsipl+=	tasp-vsipl>=20030710nb1
BUILDLINK_PKGSRCDIR.tasp-vsipl?=	../../math/tasp-vsipl
.endif # TASP_VSIPL_BUILDLINK3_MK

BUILDLINK_TREE+=	-tasp-vsipl
