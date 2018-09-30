# $NetBSD: buildlink3.mk,v 1.1 2018/09/30 18:58:16 maya Exp $

BUILDLINK_TREE+=	libaom

.if !defined(LIBAOM_BUILDLINK3_MK)
LIBAOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaom+=	libaom>=1.0.0
BUILDLINK_PKGSRCDIR.libaom?=	../../multimedia/libaom
.endif	# LIBAOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaom
