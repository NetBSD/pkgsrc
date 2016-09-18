# $NetBSD: buildlink3.mk,v 1.1 2016/09/18 16:47:55 kamil Exp $

BUILDLINK_TREE+=	linenoise

.if !defined(LINENOISE_BUILDLINK3_MK)
LINENOISE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.linenoise+=	linenoise>=1.0
BUILDLINK_PKGSRCDIR.linenoise?=	../../devel/linenoise
.endif	# LINENOISE_BUILDLINK3_MK

BUILDLINK_TREE+=	-linenoise
