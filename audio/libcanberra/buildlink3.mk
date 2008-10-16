# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/10/16 15:17:47 drochner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBCANBERRA_BUILDLINK3_MK:=	${LIBCANBERRA_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libcanberra
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibcanberra}
BUILDLINK_PACKAGES+=	libcanberra
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libcanberra

.if ${LIBCANBERRA_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libcanberra+=	libcanberra>=0.10
BUILDLINK_PKGSRCDIR.libcanberra?=	../../audio/libcanberra
.endif	# LIBCANBERRA_BUILDLINK3_MK

#.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
