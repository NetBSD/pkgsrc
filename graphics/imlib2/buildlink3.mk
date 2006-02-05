# $NetBSD: buildlink3.mk,v 1.11 2006/02/05 23:09:33 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
IMLIB2_BUILDLINK3_MK:=	${IMLIB2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	imlib2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nimlib2}
BUILDLINK_PACKAGES+=	imlib2

.if !empty(IMLIB2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.imlib2+=	imlib2>=1.1.0nb2
BUILDLINK_RECOMMENDED.imlib2+=	imlib2>=1.2.0nb4
BUILDLINK_PKGSRCDIR.imlib2?=	../../graphics/imlib2
.endif	# IMLIB2_BUILDLINK3_MK

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
