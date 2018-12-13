# $NetBSD: buildlink3.mk,v 1.4 2018/12/13 19:51:33 adam Exp $

BUILDLINK_TREE+=	mariadb-connector-c

.if !defined(MARIADB_CONNECTOR_C_BUILDLINK3_MK)
MARIADB_CONNECTOR_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mariadb-connector-c+=	mariadb-connector-c>=3.0.0
BUILDLINK_ABI_DEPENDS.mariadb-connector-c?=	mariadb-connector-c>=3.0.6nb1
BUILDLINK_PKGSRCDIR.mariadb-connector-c?=	../../databases/mariadb-connector-c

pkgbase := mariadb-connector-c
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.mariadb-connector-c:Mcurl)
.  include "../../www/curl/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.mariadb-connector-c:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
.endif

.include "../../security/openssl/buildlink3.mk"
.endif # MARIADB_CONNECTOR_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-mariadb-connector-c
