# $NetBSD: buildlink3.mk,v 1.3 2004/01/24 03:26:46 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBCDDB_BUILDLINK3_MK:=	${LIBCDDB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libcddb
.endif

.if !empty(LIBCDDB_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		libcddb
BUILDLINK_DEPENDS.libcddb+=	libcddb>=0.9.4
BUILDLINK_PKGSRCDIR.libcddb?=	../../audio/libcddb

.include "../../misc/libcdio/buildlink3.mk"

.endif # LIBCDDB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
