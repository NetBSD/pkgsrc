# $NetBSD: buildlink3.mk,v 1.1 2004/02/19 11:22:53 wiz Exp $
#
# This Makefile fragment is included by packages that use libsamplerate.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBSAMPLERATE_BUILDLINK3_MK:=	${LIBSAMPLERATE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libsamplerate
.endif

.if !empty(LIBSAMPLERATE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libsamplerate
BUILDLINK_DEPENDS.libsamplerate+=		libsamplerate>=0.0.13nb1
BUILDLINK_PKGSRCDIR.libsamplerate?=		../../audio/libsamplerate

.include "../../audio/libsndfile/buildlink3.mk"

.endif # LIBSAMPLERATE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
