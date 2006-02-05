# $NetBSD: buildlink3.mk,v 1.6 2006/02/05 23:09:58 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SYLPHEED_CLAWS_BUILDLINK3_MK:=	${SYLPHEED_CLAWS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	sylpheed-claws
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsylpheed-claws}
BUILDLINK_PACKAGES+=	sylpheed-claws

.if !empty(SYLPHEED_CLAWS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.sylpheed-claws+=	sylpheed-claws>=0.9.7nb1
BUILDLINK_RECOMMENDED.sylpheed-claws?=	sylpheed-claws>=1.0.4nb1
BUILDLINK_PKGSRCDIR.sylpheed-claws?=	../../mail/sylpheed-claws
.endif	# SYLPHEED_CLAWS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
