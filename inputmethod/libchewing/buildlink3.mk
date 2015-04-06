# $NetBSD: buildlink3.mk,v 1.10 2015/04/06 08:17:14 adam Exp $

BUILDLINK_TREE+=	libchewing

.if !defined(LIBCHEWING_BUILDLINK3_MK)
LIBCHEWING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libchewing+=		libchewing>=0.3.2
BUILDLINK_ABI_DEPENDS.libchewing+=	libchewing>=0.4.0nb2
BUILDLINK_PKGSRCDIR.libchewing?=	../../inputmethod/libchewing

.include "../../databases/sqlite3/buildlink3.mk"
.endif # LIBCHEWING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libchewing
