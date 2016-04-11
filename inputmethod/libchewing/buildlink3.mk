# $NetBSD: buildlink3.mk,v 1.11 2016/04/11 19:01:35 ryoon Exp $

BUILDLINK_TREE+=	libchewing

.if !defined(LIBCHEWING_BUILDLINK3_MK)
LIBCHEWING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libchewing+=		libchewing>=0.3.2
BUILDLINK_ABI_DEPENDS.libchewing+=	libchewing>=0.4.0nb4
BUILDLINK_PKGSRCDIR.libchewing?=	../../inputmethod/libchewing

.include "../../databases/sqlite3/buildlink3.mk"
.endif # LIBCHEWING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libchewing
