# $NetBSD: buildlink3.mk,v 1.4 2004/01/24 03:26:47 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TIFF_BUILDLINK3_MK:=	${TIFF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tiff
.endif

.if !empty(TIFF_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		tiff
BUILDLINK_DEPENDS.tiff+=	tiff>=3.5.4
BUILDLINK_PKGSRCDIR.tiff?=	../../graphics/tiff

.  include "../../devel/zlib/buildlink3.mk"
.  include "../../graphics/jpeg/buildlink3.mk"
.endif	# TIFF_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
