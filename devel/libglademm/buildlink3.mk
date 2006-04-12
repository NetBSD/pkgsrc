# $NetBSD: buildlink3.mk,v 1.5 2006/04/12 10:27:10 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGLADEMM_BUILDLINK3_MK:=	${LIBGLADEMM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libglademm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibglademm}
BUILDLINK_PACKAGES+=	libglademm

.if !empty(LIBGLADEMM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libglademm+=	libglademm>=2.6.0
BUILDLINK_ABI_DEPENDS.libglademm?=	libglademm>=2.6.1nb2
BUILDLINK_PKGSRCDIR.libglademm?=	../../devel/libglademm
.endif	# LIBGLADEMM_BUILDLINK3_MK

.include "../../devel/libglade2/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
