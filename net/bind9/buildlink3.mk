# $NetBSD: buildlink3.mk,v 1.3 2004/09/22 20:37:33 tron Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
BIND_BUILDLINK3_MK:=	${BIND_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	bind
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nbind}
BUILDLINK_PACKAGES+=	bind

.if !empty(BIND_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.bind+=	bind>=9.2.2
BUILDLINK_RECOMMENDED.bind?=	bind>=9.2.3nb4
BUILDLINK_PKGSRCDIR.bind?=	../../net/bind9

BUILDLINK_TRANSFORM.bind=	-e "s|include/bind/|include/|g"
.endif	# BIND_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
