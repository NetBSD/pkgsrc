# $NetBSD: buildlink3.mk,v 1.2 2006/02/05 23:09:34 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGGIWMH_BUILDLINK3_MK:=	${LIBGGIWMH_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libggiwmh
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibggiwmh}
BUILDLINK_PACKAGES+=	libggiwmh

.if !empty(LIBGGIWMH_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libggiwmh+=	libggiwmh>=0.2.0
BUILDLINK_RECOMMENDED.libggiwmh?=	libggiwmh>=0.2.1nb1
BUILDLINK_PKGSRCDIR.libggiwmh?=	../../graphics/libggiwmh
.endif	# LIBGGIWMH_BUILDLINK3_MK

.include "../../graphics/libggi/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
