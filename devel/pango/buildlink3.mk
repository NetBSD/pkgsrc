# $NetBSD: buildlink3.mk,v 1.2 2004/02/17 14:48:01 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PANGO_BUILDLINK3_MK:=	${PANGO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pango
.endif

.if !empty(PANGO_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		pango
BUILDLINK_DEPENDS.pango?=	pango>=1.2.5nb1
BUILDLINK_PKGSRCDIR.pango?=	../../devel/pango

.  include "../../devel/glib2/buildlink3.mk"
.  include "../../fonts/Xft2/buildlink3.mk"
.endif # PANGO_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
