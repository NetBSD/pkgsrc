# $NetBSD: buildlink3.mk,v 1.1 2026/11/24 19:22:51 adam Exp $

BUILDLINK_TREE+=	postgresql19-client

.if !defined(POSTGRESQL19_CLIENT_BUILDLINK3_MK)
POSTGRESQL19_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql19-client+=	postgresql19-client>=19.0
BUILDLINK_ABI_DEPENDS.postgresql19-client+=	postgresql19-client>=19.0
BUILDLINK_PKGSRCDIR.postgresql19-client?=	../../databases/postgresql19-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql19-client+=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql19-client+=	bin/pg_config

pkgbase := postgresql19-client
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.postgresql19-client:Mlz4}
.include "../../archivers/lz4/buildlink3.mk"
.endif

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "SunOS"
.include "../../devel/ossp-uuid/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.if ${PKG_BUILD_OPTIONS.postgresql19-client:Mgssapi}
BUILDLINK_API_DEPENDS.mit-krb5+=	mit-krb5>=1.11	# gss_store_cred_into
.  include "../../security/mit-krb5/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.postgresql19-client:Micu}
.  include "../../textproc/icu/buildlink3.mk"
.endif
.endif # POSTGRESQL19_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql19-client
