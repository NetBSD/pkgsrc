# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 05:38:35 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libwnck.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBWNCK_BUILDLINK3_MK:=	${LIBWNCK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libwnck
.endif

.if !empty(LIBWNCK_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libwnck
BUILDLINK_DEPENDS.libwnck+=		libwnck>=2.4.0.1nb1
BUILDLINK_PKGSRCDIR.libwnck?=		../../devel/libwnck

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # LIBWNCK_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
