# $NetBSD: buildlink3.mk,v 1.1 2004/04/27 04:05:41 snj Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
JADE_BUILDLINK3_MK:=	${JADE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	jade
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Njade}
BUILDLINK_PACKAGES+=	jade

.if !empty(JADE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.jade+=	jade>=1.2.1nb7
BUILDLINK_PKGSRCDIR.jade?=	../../textproc/jade
.endif	# JADE_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
