# $NetBSD: buildlink3.mk,v 1.7 2006/04/12 10:27:12 rillig Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OAF_BUILDLINK3_MK:=	${OAF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	oaf
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Noaf}
BUILDLINK_PACKAGES+=	oaf

.if !empty(OAF_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.oaf+=		oaf>=0.6.10nb4
BUILDLINK_ABI_DEPENDS.oaf+=	oaf>=0.6.10nb7
BUILDLINK_PKGSRCDIR.oaf?=	../../devel/oaf
.endif	# OAF_BUILDLINK3_MK

.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
