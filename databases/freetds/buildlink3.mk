# $NetBSD: buildlink3.mk,v 1.24 2019/07/20 22:45:59 wiz Exp $

BUILDLINK_TREE+=	freetds

.if !defined(FREETDS_BUILDLINK3_MK)
FREETDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freetds+=	freetds>=1.00
BUILDLINK_ABI_DEPENDS.freetds+=	freetds>=1.00.112nb1
BUILDLINK_PKGSRCDIR.freetds?=	../../databases/freetds

.include "../../converters/libiconv/buildlink3.mk"

pkgbase := freetds
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.freetds:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.freetds:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
.endif
.endif # FREETDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-freetds
