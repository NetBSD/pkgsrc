# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:56 joerg Exp $

BUILDLINK_TREE+=	cln

.if !defined(CLN_BUILDLINK3_MK)
CLN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cln+=		cln>=1.1.6
BUILDLINK_ABI_DEPENDS.cln+=	cln>=1.1.9nb1
BUILDLINK_PKGSRCDIR.cln?=	../../math/cln
.endif # CLN_BUILDLINK3_MK

BUILDLINK_TREE+=	-cln
