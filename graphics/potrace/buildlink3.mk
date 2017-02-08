# $NetBSD: buildlink3.mk,v 1.1 2017/02/08 17:53:51 adam Exp $

BUILDLINK_TREE+=	potrace

.if !defined(POTRACE_BUILDLINK3_MK)
POTRACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.potrace+=	potrace>=1.13
BUILDLINK_PKGSRCDIR.potrace?=	../../graphics/potrace

.endif	# POTRACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-potrace
