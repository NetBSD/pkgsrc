# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 03:26:44 xtraeme Exp $
#
# This Makefile fragment is included by packages that use jabberd.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
JABBERD_BUILDLINK3_MK:=	${JABBERD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	jabberd
.endif

.if !empty(JABBERD_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			jabberd
BUILDLINK_DEPENDS.jabberd+=		jabberd>=1.4.3nb1
BUILDLINK_PKGSRCDIR.jabberd?=		../../chat/jabberd

.include "../../devel/pth/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.endif # JABBERD_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
