# $NetBSD: buildlink3.mk,v 1.1 2004/03/07 14:10:39 minskim Exp $
#
# This Makefile fragment is included by packages that use libdockapp.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBDOCKAPP_BUILDLINK3_MK:=	${LIBDOCKAPP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libdockapp
.endif

.if !empty(LIBDOCKAPP_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libdockapp
BUILDLINK_DEPENDS.libdockapp+=		libdockapp>=0.4.0
BUILDLINK_PKGSRCDIR.libdockapp?=		../../devel/libdockapp

.include "../../graphics/xpm/buildlink3.mk"

.endif # LIBDOCKAPP_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
