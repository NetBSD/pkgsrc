# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 08:59:40 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libdvdread.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBDVDREAD_BUILDLINK3_MK:=	${LIBDVDREAD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libdvdread
.endif

.if !empty(LIBDVDREAD_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libdvdread
BUILDLINK_DEPENDS.libdvdread+=		libdvdread>=0.9.4
BUILDLINK_PKGSRCDIR.libdvdread?=	../../multimedia/libdvdread

.endif # LIBDVDREAD_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
