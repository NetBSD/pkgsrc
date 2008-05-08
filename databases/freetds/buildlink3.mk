# $NetBSD: buildlink3.mk,v 1.12 2008/05/08 20:14:10 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FREETDS_BUILDLINK3_MK:=	${FREETDS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	freetds
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfreetds}
BUILDLINK_PACKAGES+=	freetds
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}freetds

.if !empty(FREETDS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.freetds+=	freetds>=0.82
BUILDLINK_ABI_DEPENDS.freetds?=	freetds>=0.63nb4
BUILDLINK_PKGSRCDIR.freetds?=	../../databases/freetds
.endif	# FREETDS_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"

pkgbase := freetds
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.freetds:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.freetds:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
