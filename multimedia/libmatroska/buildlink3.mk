# $NetBSD: buildlink3.mk,v 1.12 2006/04/06 06:22:26 reed Exp $
#
# This Makefile fragment is included by packages that use libmatroska.
#

BUILDLINK_DEPMETHOD.libmatroska?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMATROSKA_BUILDLINK3_MK:=	${LIBMATROSKA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmatroska
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmatroska}
BUILDLINK_PACKAGES+=	libmatroska

.if !empty(LIBMATROSKA_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libmatroska+=	libmatroska>=0.8.0
BUILDLINK_ABI_DEPENDS.libmatroska?=	libmatroska>=0.8.0nb1
BUILDLINK_PKGSRCDIR.libmatroska?=	../../multimedia/libmatroska
.endif	# LIBMATROSKA_BUILDLINK3_MK

.include "../../devel/libebml/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
