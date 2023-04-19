# $NetBSD: buildlink3.mk,v 1.27 2023/04/19 08:08:27 adam Exp $

BUILDLINK_TREE+=	libchewing

.if !defined(LIBCHEWING_BUILDLINK3_MK)
LIBCHEWING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libchewing+=	libchewing>=0.3.2
BUILDLINK_ABI_DEPENDS.libchewing+=	libchewing>=0.5.1nb5
BUILDLINK_PKGSRCDIR.libchewing?=	../../inputmethod/libchewing

.include "../../databases/sqlite3/buildlink3.mk"
.endif # LIBCHEWING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libchewing
