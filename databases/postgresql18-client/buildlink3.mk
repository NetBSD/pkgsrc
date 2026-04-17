# $NetBSD: buildlink3.mk,v 1.2 2026/04/17 09:38:55 adam Exp $

BUILDLINK_TREE+=	postgresql18-client

.if !defined(POSTGRESQL18_CLIENT_BUILDLINK3_MK)
POSTGRESQL18_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql18-client+=	postgresql18-client>=18.0
BUILDLINK_ABI_DEPENDS.postgresql18-client+=	postgresql18-client>=18.0
BUILDLINK_PKGSRCDIR.postgresql18-client?=	../../databases/postgresql18-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql18-client+=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql18-client+=	bin/pg_config

pkgbase := postgresql18-client
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.postgresql18-client:Mlz4}
.include "../../archivers/lz4/buildlink3.mk"
.endif

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "SunOS"
.include "../../devel/ossp-uuid/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.if ${PKG_BUILD_OPTIONS.postgresql18-client:Mgssapi}
BUILDLINK_API_DEPENDS.mit-krb5+=	mit-krb5>=1.11	# gss_store_cred_into
.  include "../../security/mit-krb5/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.postgresql18-client:Micu}
.  include "../../textproc/icu/buildlink3.mk"
.endif
.endif # POSTGRESQL18_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql18-client
