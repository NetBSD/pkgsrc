# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:10:57 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PERDITION_BUILDLINK3_MK:=	${PERDITION_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	perdition
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nperdition}
BUILDLINK_PACKAGES+=	perdition
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}perdition

.if !empty(PERDITION_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.perdition+=	perdition>=1.17
BUILDLINK_ABI_DEPENDS.perdition?=	perdition>=1.17nb1
BUILDLINK_PKGSRCDIR.perdition?=	../../mail/perdition
.endif	# PERDITION_BUILDLINK3_MK

# The following are included in Makefile.common for "configure"'s sake.
#.include "../../devel/popt/buildlink3.mk"
#.include "../../devel/vanessa_adt/buildlink3.mk"
#.include "../../devel/vanessa_logger/buildlink3.mk"
#.include "../../devel/vanessa_socket/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
