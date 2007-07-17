# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/07/17 19:10:48 drochner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSEXYMM_BUILDLINK3_MK:=	${LIBSEXYMM_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libsexymm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibsexymm}
BUILDLINK_PACKAGES+=	libsexymm
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libsexymm

.if ${LIBSEXYMM_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libsexymm+=	libsexymm>=0.1.9
BUILDLINK_PKGSRCDIR.libsexymm?=	../../devel/libsexymm
.endif	# LIBSEXYMM_BUILDLINK3_MK

.include "../../x11/gtkmm/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
