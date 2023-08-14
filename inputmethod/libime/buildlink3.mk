# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:24:41 wiz Exp $

BUILDLINK_TREE+=	libime

.if !defined(LIBIME_BUILDLINK3_MK)
LIBIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libime+=	libime>=1.0.3
BUILDLINK_ABI_DEPENDS.libime?=	libime>=1.0.4nb8
BUILDLINK_PKGSRCDIR.libime?=	../../inputmethod/libime

.endif	# LIBIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-libime
