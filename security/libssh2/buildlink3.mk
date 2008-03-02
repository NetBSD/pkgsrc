# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/03/02 14:11:54 bjs Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBSSH2_BUILDLINK3_MK:=	${LIBSSH2_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libssh2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibssh2}
BUILDLINK_PACKAGES+=	libssh2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libssh2

.if ${LIBSSH2_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libssh2+=	libssh2>=0.18
BUILDLINK_PKGSRCDIR.libssh2?=	../../security/libssh2
.endif	# LIBSSH2_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
