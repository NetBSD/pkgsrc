# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:13:02 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBDV_BUILDLINK3_MK:=	${LIBDV_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libdv
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibdv}
BUILDLINK_PACKAGES+=	libdv

.if !empty(LIBDV_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libdv+=	libdv>=0.102
BUILDLINK_RECOMMENDED.libdv+=	libdv>=0.102nb1
BUILDLINK_PKGSRCDIR.libdv?=	../../multimedia/libdv
.endif	# LIBDV_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
