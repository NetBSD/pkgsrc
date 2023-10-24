# $NetBSD: buildlink3.mk,v 1.3 2023/10/24 22:08:37 wiz Exp $

BUILDLINK_TREE+=	postgresql16-client

.if !defined(POSTGRESQL16_CLIENT_BUILDLINK3_MK)
POSTGRESQL16_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql16-client+=	postgresql16-client>=16.0
BUILDLINK_ABI_DEPENDS.postgresql16-client+=	postgresql16-client>=16.0nb1
BUILDLINK_PKGSRCDIR.postgresql16-client?=	../../databases/postgresql16-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql16-client+=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql16-client+=	bin/pg_config

pkgbase := postgresql16-client
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.postgresql16-client:Mlz4}
.include "../../archivers/lz4/buildlink3.mk"
.endif

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "SunOS"
.include "../../devel/ossp-uuid/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.if ${PKG_BUILD_OPTIONS.postgresql16-client:Mgssapi}
.  include "../../security/mit-krb5/buildlink3.mk"
.endif
.endif # POSTGRESQL16_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql16-client
