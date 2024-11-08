# $NetBSD: buildlink3.mk,v 1.1 2024/11/08 13:43:37 adam Exp $

BUILDLINK_TREE+=	postgresql17-client

.if !defined(POSTGRESQL17_CLIENT_BUILDLINK3_MK)
POSTGRESQL17_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql17-client+=	postgresql17-client>=17.0
BUILDLINK_ABI_DEPENDS.postgresql17-client+=	postgresql17-client>=17.0
BUILDLINK_PKGSRCDIR.postgresql17-client?=	../../databases/postgresql17-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql17-client+=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql17-client+=	bin/pg_config

pkgbase := postgresql17-client
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.postgresql17-client:Mlz4}
.include "../../archivers/lz4/buildlink3.mk"
.endif

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "SunOS"
.include "../../devel/ossp-uuid/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.if ${PKG_BUILD_OPTIONS.postgresql17-client:Mgssapi}
BUILDLINK_API_DEPENDS.mit-krb5+=	mit-krb5>=1.11	# gss_store_cred_into
.  include "../../security/mit-krb5/buildlink3.mk"
.endif
.endif # POSTGRESQL17_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql17-client
