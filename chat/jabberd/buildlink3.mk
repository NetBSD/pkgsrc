# $NetBSD: buildlink3.mk,v 1.3 2004/03/05 19:25:08 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
JABBERD_BUILDLINK3_MK:=	${JABBERD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	jabberd
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Njabberd}
BUILDLINK_PACKAGES+=	jabberd

.if !empty(JABBERD_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.jabberd+=	jabberd>=1.4.2
BUILDLINK_PKGSRCDIR.jabberd?=	../../chat/jabberd

.include "../../security/openssl/buildlink3.mk"

.endif	# JABBERD_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
