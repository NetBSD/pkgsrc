# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 22:39:02 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
JABBERD_BUILDLINK3_MK:=	${JABBERD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	jabberd
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Njabberd}
BUILDLINK_PACKAGES+=	jabberd
BUILDLINK_ORDER+=	jabberd

.if !empty(JABBERD_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.jabberd+=	jabberd>=1.4.2
BUILDLINK_ABI_DEPENDS.jabberd?=	jabberd>=1.4.2nb5
BUILDLINK_PKGSRCDIR.jabberd?=	../../chat/jabberd
.endif	# JABBERD_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
