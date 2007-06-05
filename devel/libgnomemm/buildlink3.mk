# $NetBSD: buildlink3.mk,v 1.13 2007/06/05 05:37:10 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGNOMEMM_BUILDLINK3_MK:=	${LIBGNOMEMM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomemm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomemm}
BUILDLINK_PACKAGES+=	libgnomemm
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgnomemm

.if !empty(LIBGNOMEMM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgnomemm+=	libgnomemm>=2.10.0
BUILDLINK_ABI_DEPENDS.libgnomemm+=	libgnomemm>=2.18.0nb1
BUILDLINK_PKGSRCDIR.libgnomemm?=	../../devel/libgnomemm
.endif	# LIBGNOMEMM_BUILDLINK3_MK

.include "../../devel/libgnome/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
