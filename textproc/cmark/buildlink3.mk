# $NetBSD: buildlink3.mk,v 1.1 2018/01/18 17:11:38 adam Exp $

BUILDLINK_TREE+=	cmark

.if !defined(CMARK_BUILDLINK3_MK)
CMARK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cmark+=	cmark>=0.28.3
BUILDLINK_PKGSRCDIR.cmark?=	../../textproc/cmark
.endif	# CMARK_BUILDLINK3_MK

BUILDLINK_TREE+=	-cmark
