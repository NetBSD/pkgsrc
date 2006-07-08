# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 22:39:01 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSNDFILE_BUILDLINK3_MK:=	${LIBSNDFILE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libsndfile
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibsndfile}
BUILDLINK_PACKAGES+=	libsndfile
BUILDLINK_ORDER+=	libsndfile

.if !empty(LIBSNDFILE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libsndfile+=		libsndfile>=1.0.0
BUILDLINK_ABI_DEPENDS.libsndfile+=	libsndfile>=1.0.13nb1
BUILDLINK_PKGSRCDIR.libsndfile?=	../../audio/libsndfile
.endif	# LIBSNDFILE_BUILDLINK3_MK

.include "../../audio/flac/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
