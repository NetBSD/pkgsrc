# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/04/11 00:08:11 rh Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNUSTEP_SSL_BUILDLINK3_MK:=	${GNUSTEP_SSL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnustep-ssl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnustep-ssl}
BUILDLINK_PACKAGES+=	gnustep-ssl

.if !empty(GNUSTEP_SSL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnustep-ssl+=		gnustep-ssl>=1.9.1
BUILDLINK_PKGSRCDIR.gnustep-ssl?=	../../security/gnustep-ssl
.endif	# GNUSTEP_SSL_BUILDLINK3_MK

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
