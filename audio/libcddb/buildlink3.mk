# $NetBSD: buildlink3.mk,v 1.6 2004/10/03 00:13:07 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBCDDB_BUILDLINK3_MK:=	${LIBCDDB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libcddb
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibcddb}
BUILDLINK_PACKAGES+=	libcddb

.if !empty(LIBCDDB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libcddb+=	libcddb>=0.9.4
BUILDLINK_RECOMMENDED.libcddb+=	libcddb>=0.9.5nb1
BUILDLINK_PKGSRCDIR.libcddb?=	../../audio/libcddb
.endif	# LIBCDDB_BUILDLINK3_MK

.include "../../misc/libcdio/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
