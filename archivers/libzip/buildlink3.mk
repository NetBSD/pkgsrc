# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/06/22 21:11:39 dillo Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBZIP_BUILDLINK3_MK:=	${LIBZIP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libzip
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibzip}
BUILDLINK_PACKAGES+=	libzip

.if !empty(LIBZIP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libzip+=	libzip>=0.6
BUILDLINK_PKGSRCDIR.libzip?=	../../archivers/libzip
.endif	# LIBZIP_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
