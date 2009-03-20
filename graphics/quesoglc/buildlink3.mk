# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:44 joerg Exp $

BUILDLINK_TREE+=	quesoglc

.if !defined(QUESOGLC_BUILDLINK3_MK)
QUESOGLC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.quesoglc+=	quesoglc>=0.7.1
BUILDLINK_PKGSRCDIR.quesoglc?=	../../graphics/quesoglc
.endif # QUESOGLC_BUILDLINK3_MK

BUILDLINK_TREE+=	-quesoglc
