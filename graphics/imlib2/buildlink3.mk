# $NetBSD: buildlink3.mk,v 1.17 2006/11/06 11:28:32 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
IMLIB2_BUILDLINK3_MK:=	${IMLIB2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	imlib2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nimlib2}
BUILDLINK_PACKAGES+=	imlib2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}imlib2

.if !empty(IMLIB2_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.imlib2+=	imlib2>=1.1.0nb2
BUILDLINK_ABI_DEPENDS.imlib2+=	imlib2>=1.2.0nb5
BUILDLINK_PKGSRCDIR.imlib2?=	../../graphics/imlib2
.endif	# IMLIB2_BUILDLINK3_MK

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
