# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:59 joerg Exp $

BUILDLINK_TREE+=	slatec

.if !defined(SLATEC_BUILDLINK3_MK)
SLATEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.slatec+=	slatec>=4.1nb1
BUILDLINK_ABI_DEPENDS.slatec+=	slatec>=4.1nb2
BUILDLINK_PKGSRCDIR.slatec?=	../../math/slatec
.endif # SLATEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-slatec
