# $NetBSD: buildlink3.mk,v 1.1 2004/02/17 23:52:45 jmmv Exp $
#
# This Makefile fragment is included by packages that use libsidplay.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBSIDPLAY_BUILDLINK3_MK:=	${LIBSIDPLAY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libsidplay
.endif

.if !empty(LIBSIDPLAY_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libsidplay
BUILDLINK_DEPENDS.libsidplay+=		libsidplay>=1.36.38
BUILDLINK_PKGSRCDIR.libsidplay?=		../../audio/libsidplay

.endif # LIBSIDPLAY_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
