# $NetBSD: buildlink3.mk,v 1.1 2021/02/20 21:27:37 ryoon Exp $

BUILDLINK_TREE+=	libime

.if !defined(LIBIME_BUILDLINK3_MK)
LIBIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libime+=	libime>=1.0.3
BUILDLINK_PKGSRCDIR.libime?=	../../inputmethod/libime

.endif	# LIBIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-libime
