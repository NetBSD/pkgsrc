# $NetBSD: buildlink3.mk,v 1.12 2009/02/21 13:20:45 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSNDFILE_BUILDLINK3_MK:=	${LIBSNDFILE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libsndfile
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibsndfile}
BUILDLINK_PACKAGES+=	libsndfile
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libsndfile

.if !empty(LIBSNDFILE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libsndfile+=	libsndfile>=1.0.0
BUILDLINK_ABI_DEPENDS.libsndfile+=	libsndfile>=1.0.18
BUILDLINK_PKGSRCDIR.libsndfile?=	../../audio/libsndfile
.endif	# LIBSNDFILE_BUILDLINK3_MK

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
