# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:25:28 joerg Exp $
#

BUILDLINK_TREE+=	chasen-base

.if !defined(CHASEN_BASE_BUILDLINK3_MK)
CHASEN_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.chasen-base+=	chasen-base>=2.3.3
BUILDLINK_ABI_DEPENDS.chasen-base+=	chasen-base>=2.3.3nb1
BUILDLINK_PKGSRCDIR.chasen-base?=	../../textproc/chasen-base

.include "../../devel/darts/buildlink3.mk"
.endif # CHASEN_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-chasen-base
