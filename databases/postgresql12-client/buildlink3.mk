# $NetBSD: buildlink3.mk,v 1.6 2023/07/09 13:57:20 nia Exp $

BUILDLINK_TREE+=	postgresql12-client

.if !defined(POSTGRESQL12_CLIENT_BUILDLINK3_MK)
POSTGRESQL12_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql12-client+=	postgresql12-client>=12.0
BUILDLINK_ABI_DEPENDS.postgresql12-client+=	postgresql12-client>=12.11nb1
BUILDLINK_PKGSRCDIR.postgresql12-client?=	../../databases/postgresql12-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql12-client=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql12-client+=	bin/pg_config

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "SunOS"
.include "../../devel/ossp-uuid/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

pkgbase := postgresql12-client
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.postgresql12-client:Mgssapi}
.  include "../../mk/krb5.buildlink3.mk"
.endif
.endif # POSTGRESQL12_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql12-client
