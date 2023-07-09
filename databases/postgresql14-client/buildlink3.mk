# $NetBSD: buildlink3.mk,v 1.4 2023/07/09 13:57:20 nia Exp $

BUILDLINK_TREE+=	postgresql14-client

.if !defined(POSTGRESQL14_CLIENT_BUILDLINK3_MK)
POSTGRESQL14_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql14-client+=	postgresql14-client>=14.0
BUILDLINK_ABI_DEPENDS.postgresql14-client+=	postgresql14-client>=14.4nb1
BUILDLINK_PKGSRCDIR.postgresql14-client?=	../../databases/postgresql14-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql14-client+=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql14-client+=	bin/pg_config

pkgbase := postgresql14-client
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.postgresql14-client:Mlz4}
.include "../../archivers/lz4/buildlink3.mk"
.endif

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "SunOS"
.include "../../devel/ossp-uuid/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.if ${PKG_BUILD_OPTIONS.postgresql14-client:Mgssapi}
.  include "../../mk/krb5.buildlink3.mk"
.endif
.endif # POSTGRESQL14_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql14-client
