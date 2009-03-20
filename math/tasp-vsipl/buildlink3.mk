# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:59 joerg Exp $

BUILDLINK_TREE+=	tasp-vsipl

.if !defined(TASP_VSIPL_BUILDLINK3_MK)
TASP_VSIPL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tasp-vsipl+=	tasp-vsipl>=20030710
BUILDLINK_ABI_DEPENDS.tasp-vsipl?=	tasp-vsipl>=20030710nb1
BUILDLINK_PKGSRCDIR.tasp-vsipl?=	../../math/tasp-vsipl
.endif # TASP_VSIPL_BUILDLINK3_MK

BUILDLINK_TREE+=	-tasp-vsipl
