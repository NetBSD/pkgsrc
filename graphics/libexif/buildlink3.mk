# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 04:58:15 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libexif.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBEXIF_BUILDLINK3_MK:=	${LIBEXIF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libexif
.endif

.if !empty(LIBEXIF_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libexif
BUILDLINK_DEPENDS.libexif+=		libexif>=0.5.12
BUILDLINK_PKGSRCDIR.libexif?=		../../graphics/libexif

.include "../../devel/gettext-lib/buildlink3.mk"

.endif # LIBEXIF_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
