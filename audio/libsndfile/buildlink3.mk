# $NetBSD: buildlink3.mk,v 1.6 2006/02/05 23:08:11 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSNDFILE_BUILDLINK3_MK:=	${LIBSNDFILE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libsndfile
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibsndfile}
BUILDLINK_PACKAGES+=	libsndfile

.if !empty(LIBSNDFILE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libsndfile+=		libsndfile>=1.0.0
BUILDLINK_RECOMMENDED.libsndfile+=	libsndfile>=1.0.13nb1
BUILDLINK_PKGSRCDIR.libsndfile?=	../../audio/libsndfile
.endif	# LIBSNDFILE_BUILDLINK3_MK

.include "../../audio/flac/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
