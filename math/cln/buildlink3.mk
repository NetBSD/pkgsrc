# $NetBSD: buildlink3.mk,v 1.10 2009/09/09 17:29:01 drochner Exp $

BUILDLINK_TREE+=	cln

.if !defined(CLN_BUILDLINK3_MK)
CLN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cln+=		cln>=1.1.6
BUILDLINK_ABI_DEPENDS.cln+=	cln>=1.3.0
BUILDLINK_PKGSRCDIR.cln?=	../../math/cln
.endif # CLN_BUILDLINK3_MK

BUILDLINK_TREE+=	-cln
