# $NetBSD: buildlink3.mk,v 1.1 2004/03/11 06:45:55 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ZZIPLIB_BUILDLINK3_MK:=	${ZZIPLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	zziplib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nzziplib}
BUILDLINK_PACKAGES+=	zziplib

.if !empty(ZZIPLIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.zziplib+=	zziplib>=0.10.82
BUILDLINK_PKGSRCDIR.zziplib?=	../../archivers/zziplib

.include "../../devel/zlib/buildlink3.mk"

.endif	# ZZIPLIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
