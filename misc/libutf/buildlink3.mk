# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:25:00 joerg Exp $

BUILDLINK_TREE+=	libutf

.if !defined(LIBUTF_BUILDLINK3_MK)
LIBUTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libutf+=	libutf>=3.0
BUILDLINK_PKGSRCDIR.libutf?=	../../misc/libutf
.endif # LIBUTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libutf
