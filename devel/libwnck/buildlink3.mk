# $NetBSD: buildlink3.mk,v 1.16 2007/11/05 11:36:17 drochner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBWNCK_BUILDLINK3_MK:=	${LIBWNCK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libwnck
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibwnck}
BUILDLINK_PACKAGES+=	libwnck
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libwnck

.if !empty(LIBWNCK_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libwnck+=	libwnck>=2.20.0
BUILDLINK_ABI_DEPENDS.libwnck?=	libwnck>=2.20.0
BUILDLINK_PKGSRCDIR.libwnck?=	../../devel/libwnck
.endif	# LIBWNCK_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
