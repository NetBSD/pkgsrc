# $NetBSD: buildlink3.mk,v 1.2 2007/07/29 17:35:14 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBARCHIVE_BUILDLINK3_MK:=	${LIBARCHIVE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libarchive
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibarchive}
BUILDLINK_PACKAGES+=	libarchive
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libarchive

.if ${LIBARCHIVE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libarchive+=	libarchive>=2.2
BUILDLINK_PKGSRCDIR.libarchive?=	../../archivers/libarchive
.endif	# LIBARCHIVE_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
