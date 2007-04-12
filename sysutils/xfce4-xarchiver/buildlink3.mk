# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/04/12 09:47:14 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_XARCHIVER_BUILDLINK3_MK:=	${XFCE4_XARCHIVER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-xarchiver
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-xarchiver}
BUILDLINK_PACKAGES+=	xfce4-xarchiver
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-xarchiver

.if ${XFCE4_XARCHIVER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-xarchiver+=	xfce4-xarchiver>=0.4.6
BUILDLINK_PKGSRCDIR.xfce4-xarchiver?=	../../sysutils/xfce4-xarchiver
.endif	# XFCE4_XARCHIVER_BUILDLINK3_MK

.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
