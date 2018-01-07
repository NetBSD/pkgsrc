# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:07 rillig Exp $

BUILDLINK_TREE+=	linenoise

.if !defined(LINENOISE_BUILDLINK3_MK)
LINENOISE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.linenoise+=	linenoise>=1.0
BUILDLINK_PKGSRCDIR.linenoise?=		../../devel/linenoise
.endif	# LINENOISE_BUILDLINK3_MK

BUILDLINK_TREE+=	-linenoise
