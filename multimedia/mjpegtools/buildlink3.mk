# $NetBSD: buildlink3.mk,v 1.1 2004/02/18 00:13:28 jmmv Exp $
#
# This Makefile fragment is included by packages that use mjpegtools.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MJPEGTOOLS_BUILDLINK3_MK:=	${MJPEGTOOLS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mjpegtools
.endif

.if !empty(MJPEGTOOLS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			mjpegtools
BUILDLINK_DEPENDS.mjpegtools+=		mjpegtools>=1.6.1.90nb3
BUILDLINK_PKGSRCDIR.mjpegtools?=		../../multimedia/mjpegtools

.include "../../audio/lame/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

.endif # MJPEGTOOLS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
