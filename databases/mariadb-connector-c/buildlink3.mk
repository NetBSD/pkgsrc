# $NetBSD: buildlink3.mk,v 1.14 2021/05/13 11:46:13 nia Exp $

BUILDLINK_TREE+=	mariadb-connector-c

.if !defined(MARIADB_CONNECTOR_C_BUILDLINK3_MK)
MARIADB_CONNECTOR_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mariadb-connector-c+=	mariadb-connector-c>=3.0.0
BUILDLINK_ABI_DEPENDS.mariadb-connector-c?=	mariadb-connector-c>=3.0.6nb10
BUILDLINK_PKGSRCDIR.mariadb-connector-c?=	../../databases/mariadb-connector-c

pkgbase := mariadb-connector-c
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.mariadb-connector-c:Mcurl}
.  include "../../www/curl/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.mariadb-connector-c:Mkerberos}
.  include "../../mk/krb5.buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.mariadb-connector-c:Mgnutls}
.  include "../../security/gnutls/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.mariadb-connector-c:Mopenssl}
.  include "../../security/openssl/buildlink3.mk"
.endif
.endif # MARIADB_CONNECTOR_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-mariadb-connector-c
