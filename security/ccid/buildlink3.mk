# $NetBSD: buildlink3.mk,v 1.4 2012/12/15 00:29:31 pettai Exp $

BUILDLINK_TREE+=	ccid

.if !defined(CCID_BUILDLINK3_MK)
CCID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ccid+=	ccid>=1.4.0
BUILDLINK_PKGSRCDIR.ccid?=	../../security/ccid

.include "../../security/pcsc-lite/buildlink3.mk"
.endif # CCID_BUILDLINK3_MK

BUILDLINK_TREE+=	-ccid
