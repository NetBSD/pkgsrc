# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/02/06 09:26:36 bjs Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMP3SPLT_BUILDLINK3_MK:=	${LIBMP3SPLT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libmp3splt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmp3splt}
BUILDLINK_PACKAGES+=	libmp3splt
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libmp3splt

.if ${LIBMP3SPLT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libmp3splt+=	libmp3splt>=0.4rc1
BUILDLINK_PKGSRCDIR.libmp3splt?=	../../audio/libmp3splt
.endif	# LIBMP3SPLT_BUILDLINK3_MK
###
### XXX libmad and libvorbis are needed only for headers.
###
BUILDLINK_DEPMETHOD.libmad?=	build
.include "../../audio/libmad/buildlink3.mk"

BUILDLINK_DEPMETHOD.libvorbis?= build
.include "../../audio/libvorbis/buildlink3.mk"

.include "../../multimedia/libogg/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
