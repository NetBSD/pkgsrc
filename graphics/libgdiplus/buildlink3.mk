# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/02/03 12:31:35 recht Exp $
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGDIPLUS_BUILDLINK3_MK:=	${LIBGDIPLUS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgdiplus
.endif

.if !empty(LIBGDIPLUS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libgdiplus
BUILDLINK_DEPENDS.libgdiplus?=		libgdiplus>=0.1
BUILDLINK_PKGSRCDIR.libgdiplus?=		../../graphics/libgdiplus

.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

.endif # LIBGDIPLUS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
