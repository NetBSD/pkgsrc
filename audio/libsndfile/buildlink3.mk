# $NetBSD: buildlink3.mk,v 1.1 2004/02/17 19:13:28 wiz Exp $
#
# This Makefile fragment is included by packages that use libsndfile.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBSNDFILE_BUILDLINK3_MK:=	${LIBSNDFILE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libsndfile
.endif

.if !empty(LIBSNDFILE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libsndfile
BUILDLINK_DEPENDS.libsndfile+=		libsndfile>=1.0.0
BUILDLINK_PKGSRCDIR.libsndfile?=	../../audio/libsndfile

.endif # LIBSNDFILE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
