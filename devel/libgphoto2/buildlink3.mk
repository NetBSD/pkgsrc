# $NetBSD: buildlink3.mk,v 1.1 2004/02/21 22:58:08 cube Exp $
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGPHOTO2_BUILDLINK3_MK:=	${LIBGPHOTO2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgphoto2
.endif

.if !empty(LIBGPHOTO2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libgphoto2
BUILDLINK_DEPENDS.libgphoto2+=		libgphoto2>=2.1.2
BUILDLINK_PKGSRCDIR.libgphoto2?=		../../devel/libgphoto2
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"

.endif # LIBGPHOTO2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
