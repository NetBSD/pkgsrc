# $NetBSD: buildlink3.mk,v 1.9 2004/12/22 03:57:15 reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TIFF_BUILDLINK3_MK:=	${TIFF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tiff
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntiff}
BUILDLINK_PACKAGES+=	tiff

.if !empty(TIFF_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.tiff+=	tiff>=3.6.1
BUILDLINK_RECOMMENDED.tiff+=	tiff>=3.6.1nb6
BUILDLINK_PKGSRCDIR.tiff?=	../../graphics/tiff
.endif	# TIFF_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
