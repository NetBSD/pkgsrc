# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:28 joerg Exp $

BUILDLINK_TREE+=	enca

.if !defined(ENCA_BUILDLINK3_MK)
ENCA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.enca+=	enca>=1.9
BUILDLINK_PKGSRCDIR.enca?=	../../textproc/enca
.endif # ENCA_BUILDLINK3_MK

BUILDLINK_TREE+=	-enca
