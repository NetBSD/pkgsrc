# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/09/06 22:55:05 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGPOD_BUILDLINK3_MK:=	${LIBGPOD_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libgpod
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgpod}
BUILDLINK_PACKAGES+=	libgpod
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgpod

.if ${LIBGPOD_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libgpod+=	libgpod>=0.3.2
BUILDLINK_PKGSRCDIR.libgpod?=	../../audio/libgpod
.endif	# LIBGPOD_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
