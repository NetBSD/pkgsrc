# $NetBSD: buildlink3.mk,v 1.4 2004/03/18 09:12:09 jlam Exp $

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
.endif	# JABBERD_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
