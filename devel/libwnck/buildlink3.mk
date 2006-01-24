# $NetBSD: buildlink3.mk,v 1.8 2006/01/24 07:32:04 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBWNCK_BUILDLINK3_MK:=	${LIBWNCK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libwnck
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibwnck}
BUILDLINK_PACKAGES+=	libwnck

.if !empty(LIBWNCK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libwnck+=	libwnck>=2.10.0
BUILDLINK_RECOMMENDED.libwnck?=	libwnck>=2.12.2nb1
BUILDLINK_PKGSRCDIR.libwnck?=	../../devel/libwnck
.endif	# LIBWNCK_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
