# $NetBSD: buildlink3.mk,v 1.13 2006/07/08 23:10:43 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GLIB2_BUILDLINK3_MK:=	${GLIB2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	glib2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nglib2}
BUILDLINK_PACKAGES+=	glib2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}glib2

.if !empty(GLIB2_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.4.0
BUILDLINK_ABI_DEPENDS.glib2+=	glib2>=2.8.6nb1
BUILDLINK_PKGSRCDIR.glib2?=	../../devel/glib2
.endif	# GLIB2_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
