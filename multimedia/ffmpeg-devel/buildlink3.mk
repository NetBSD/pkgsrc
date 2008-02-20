# $NetBSD: buildlink3.mk,v 1.4 2008/02/20 10:12:04 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
FFMPEG_DEVEL_BUILDLINK3_MK:=	${FFMPEG_DEVEL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ffmpeg-devel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nffmpeg-devel}
BUILDLINK_PACKAGES+=	ffmpeg-devel
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ffmpeg-devel

.if ${FFMPEG_DEVEL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ffmpeg-devel+=	ffmpeg-devel>=20071004
BUILDLINK_PKGSRCDIR.ffmpeg-devel?=	../../multimedia/ffmpeg-devel
.endif	# FFMPEG_DEVEL_BUILDLINK3_MK

.include "../../devel/libgetopt/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
