# $NetBSD: buildlink3.mk,v 1.1 2004/03/10 11:53:37 xtraeme Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.3.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_PRINT_BUILDLINK3_MK:=	${XFCE4_PRINT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-print
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-print}
BUILDLINK_PACKAGES+=	xfce4-print

.if !empty(XFCE4_PRINT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-print+=	xfce4-print>=4.0.4nb1
BUILDLINK_PKGSRCDIR.xfce4-print?=	../../print/xfce4-print

.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif	# XFCE4_PRINT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
