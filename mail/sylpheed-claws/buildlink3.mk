# $NetBSD: buildlink3.mk,v 1.2 2004/03/11 13:17:00 jmmv Exp $
#
# This Makefile fragment is included by packages that use sylpheed-claws.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SYLPHEED_CLAWS_BUILDLINK3_MK:=	${SYLPHEED_CLAWS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	sylpheed-claws
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsylpheed-claws}
BUILDLINK_PACKAGES+=	sylpheed-claws

.if !empty(SYLPHEED_CLAWS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.sylpheed-claws+=		sylpheed-claws>=0.9.7nb1
BUILDLINK_PKGSRCDIR.sylpheed-claws?=		../../mail/sylpheed-claws

.endif # SYLPHEED_CLAWS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
