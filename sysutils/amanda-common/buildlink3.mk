# $NetBSD: buildlink3.mk,v 1.16 2021/10/21 07:46:32 wiz Exp $

BUILDLINK_TREE+=	amanda-common

.if !defined(AMANDA_COMMON_BUILDLINK3_MK)
AMANDA_COMMON_BUILDLINK3_MK:=

.include "version.mk"

BUILDLINK_API_DEPENDS.amanda-common+=	amanda-common>=${AMANDA_VERSION}
BUILDLINK_ABI_DEPENDS.amanda-common+=	amanda-common>=3.3.9nb7
BUILDLINK_PKGSRCDIR.amanda-common?=	../../sysutils/amanda-common

BUILDLINK_LIBDIRS.amanda-common=	lib/amanda

pkgbase := amanda-common
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.amanda-common:Mamanda-krb5)
CONFIGURE_ARGS+=	--with-krb5-security=${KRB5BASE}
.  include "../../mk/krb5.buildlink3.mk"
.endif
.endif # AMANDA_COMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-amanda-common
