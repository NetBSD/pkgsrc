# $NetBSD: buildlink3.mk,v 1.13 2007/06/08 12:25:04 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBETPAN_BUILDLINK3_MK:=	${LIBETPAN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libetpan
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibetpan}
BUILDLINK_PACKAGES+=	libetpan
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libetpan

.if !empty(LIBETPAN_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libetpan+=	libetpan>=0.38nb1
BUILDLINK_ABI_DEPENDS.libetpan?=	libetpan>=0.48nb1
BUILDLINK_PKGSRCDIR.libetpan?=	../../mail/libetpan
.endif	# LIBETPAN_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
