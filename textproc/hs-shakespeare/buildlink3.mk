# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:48:01 riastradh Exp $

BUILDLINK_TREE+=	hs-shakespeare

.if !defined(HS_SHAKESPEARE_BUILDLINK3_MK)
HS_SHAKESPEARE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-shakespeare+=	hs-shakespeare>=2.0.24
BUILDLINK_ABI_DEPENDS.hs-shakespeare+=	hs-shakespeare>=2.0.24
BUILDLINK_PKGSRCDIR.hs-shakespeare?=	../../textproc/hs-shakespeare
.endif	# HS_SHAKESPEARE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-shakespeare
