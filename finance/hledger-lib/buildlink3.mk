# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:52:48 riastradh Exp $

BUILDLINK_TREE+=	hledger-lib

.if !defined(HLEDGER_LIB_BUILDLINK3_MK)
HLEDGER_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hledger-lib+=	hledger-lib>=1.17.1.1
BUILDLINK_ABI_DEPENDS.hledger-lib+=	hledger-lib>=1.17.1.1
BUILDLINK_PKGSRCDIR.hledger-lib?=	../../finance/hledger-lib
.endif	# HLEDGER_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hledger-lib
