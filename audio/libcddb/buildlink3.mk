# $NetBSD: buildlink3.mk,v 1.5 2004/03/18 09:12:08 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBCDDB_BUILDLINK3_MK:=	${LIBCDDB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libcddb
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibcddb}
BUILDLINK_PACKAGES+=	libcddb

.if !empty(LIBCDDB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libcddb+=	libcddb>=0.9.4
BUILDLINK_PKGSRCDIR.libcddb?=	../../audio/libcddb
.endif	# LIBCDDB_BUILDLINK3_MK

.include "../../misc/libcdio/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
