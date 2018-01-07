# $NetBSD: buildlink3.mk,v 1.12 2018/01/07 13:04:22 rillig Exp $

BUILDLINK_TREE+=	cln

.if !defined(CLN_BUILDLINK3_MK)
CLN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cln+=	cln>=1.1.6
BUILDLINK_ABI_DEPENDS.cln+=	cln>=1.3.2nb1
BUILDLINK_PKGSRCDIR.cln?=	../../math/cln

.include "../../devel/gmp/buildlink3.mk"
.endif # CLN_BUILDLINK3_MK

BUILDLINK_TREE+=	-cln
