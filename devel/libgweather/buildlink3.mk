# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/04/11 19:01:24 drochner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGWEATHER_BUILDLINK3_MK:=	${LIBGWEATHER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libgweather
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgweather}
BUILDLINK_PACKAGES+=	libgweather
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgweather

.if ${LIBGWEATHER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libgweather+=	libgweather>=2.22.0
BUILDLINK_PKGSRCDIR.libgweather?=	../../devel/libgweather
.endif	# LIBGWEATHER_BUILDLINK3_MK

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
