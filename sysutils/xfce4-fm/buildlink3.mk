# $NetBSD: buildlink3.mk,v 1.1 2004/03/10 11:53:37 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_FM_BUILDLINK3_MK:=	${XFCE4_FM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-fm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-fm}
BUILDLINK_PACKAGES+=	xfce4-fm

.if !empty(XFCE4_FM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-fm+=	xfce4-fm>=4.0.4nb1
BUILDLINK_PKGSRCDIR.xfce4-fm?=	../../sysutils/xfce4-fm

.include "../../databases/dbh/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif	# XFCE4_FM_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
