# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:46 joerg Exp $

BUILDLINK_TREE+=	libchewing

.if !defined(LIBCHEWING_BUILDLINK3_MK)
LIBCHEWING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libchewing+=		libchewing>=0.2.7
BUILDLINK_ABI_DEPENDS.libchewing+=	libchewing>=0.2.7
BUILDLINK_PKGSRCDIR.libchewing?=	../../inputmethod/libchewing
.endif # LIBCHEWING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libchewing
