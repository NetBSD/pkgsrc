# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 05:51:53 xtraeme Exp $
#
# This Makefile fragment is included by packages that use imlib2.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
IMLIB2_BUILDLINK3_MK:=	${IMLIB2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	imlib2
.endif

.if !empty(IMLIB2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			imlib2
BUILDLINK_DEPENDS.imlib2+=		imlib2>=1.1.0nb1
BUILDLINK_PKGSRCDIR.imlib2?=		../../graphics/imlib2

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.endif # IMLIB2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
