# $NetBSD: buildlink3.mk,v 1.3 2004/01/05 11:05:45 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
POPT_BUILDLINK3_MK:=	${POPT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	popt
.endif

.if !empty(POPT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		popt
BUILDLINK_DEPENDS.popt?=	popt>=1.7nb3
BUILDLINK_PKGSRCDIR.popt?=	../../devel/popt

.  include "../../devel/gettext-lib/buildlink3.mk"
.endif	# POPT_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
