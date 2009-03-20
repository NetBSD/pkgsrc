# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:11 joerg Exp $

BUILDLINK_TREE+=	darts

.if !defined(DARTS_BUILDLINK3_MK)
DARTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.darts+=	darts>=0.32
BUILDLINK_PKGSRCDIR.darts?=	../../devel/darts
BUILDLINK_DEPMETHOD.darts?=	build
.endif # DARTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-darts
