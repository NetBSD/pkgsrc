# $NetBSD: buildlink3.mk,v 1.8 2004/07/03 23:03:22 recht Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGDIPLUS_BUILDLINK3_MK:=	${LIBGDIPLUS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgdiplus
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgdiplus}
BUILDLINK_PACKAGES+=	libgdiplus

.if !empty(LIBGDIPLUS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgdiplus+=	libgdiplus>=1.0
BUILDLINK_PKGSRCDIR.libgdiplus?=	../../graphics/libgdiplus
.endif	# LIBGDIPLUS_BUILDLINK3_MK

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
