# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 02:54:41 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libesmtp.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBESMTP_BUILDLINK3_MK:=	${LIBESMTP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libesmtp
.endif

.if !empty(LIBESMTP_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libesmtp
BUILDLINK_DEPENDS.libesmtp+=		libesmtp>=1.0rc1nb1
BUILDLINK_PKGSRCDIR.libesmtp?=		../../mail/libesmtp

LIBESMTP=	-lesmtp

CONFIGURE_ENV+=	LIBESMTP="${LIBESMTP}"
MAKE_ENV+=	LIBESMTP="${LIBESMTP}"

.include "../../security/openssl/buildlink3.mk"

.endif # LIBESMTP_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
