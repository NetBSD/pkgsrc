# $NetBSD: buildlink3.mk,v 1.3 2023/10/24 22:08:36 wiz Exp $

BUILDLINK_TREE+=	postgresql15-client

.if !defined(POSTGRESQL15_CLIENT_BUILDLINK3_MK)
POSTGRESQL15_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql15-client+=	postgresql15-client>=15.0
BUILDLINK_ABI_DEPENDS.postgresql15-client+=	postgresql15-client>=15.4nb1
BUILDLINK_PKGSRCDIR.postgresql15-client?=	../../databases/postgresql15-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql15-client+=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql15-client+=	bin/pg_config

pkgbase := postgresql15-client
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.postgresql15-client:Mlz4}
.include "../../archivers/lz4/buildlink3.mk"
.endif

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "SunOS"
.include "../../devel/ossp-uuid/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.if ${PKG_BUILD_OPTIONS.postgresql15-client:Mgssapi}
.  include "../../mk/krb5.buildlink3.mk"
.endif
.endif # POSTGRESQL15_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql15-client
