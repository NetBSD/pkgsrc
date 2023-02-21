# $NetBSD: buildlink3.mk,v 1.6 2023/02/21 16:32:33 adam Exp $

BUILDLINK_TREE+=	ccid

.if !defined(CCID_BUILDLINK3_MK)
CCID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ccid+=	ccid>=1.4.0
BUILDLINK_ABI_DEPENDS.ccid+=	ccid>=1.5.0nb1
BUILDLINK_PKGSRCDIR.ccid?=	../../security/ccid

.include "../../security/pcsc-lite/buildlink3.mk"
.endif # CCID_BUILDLINK3_MK

BUILDLINK_TREE+=	-ccid
