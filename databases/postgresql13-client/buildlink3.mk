# $NetBSD: buildlink3.mk,v 1.6 2023/10/24 22:08:35 wiz Exp $

BUILDLINK_TREE+=	postgresql13-client

.if !defined(POSTGRESQL13_CLIENT_BUILDLINK3_MK)
POSTGRESQL13_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql13-client+=	postgresql13-client>=13.0
BUILDLINK_ABI_DEPENDS.postgresql13-client+=	postgresql13-client>=13.12nb1
BUILDLINK_PKGSRCDIR.postgresql13-client?=	../../databases/postgresql13-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql13-client=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql13-client+=	bin/pg_config

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "SunOS"
.include "../../devel/ossp-uuid/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

pkgbase := postgresql13-client
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.postgresql13-client:Mgssapi}
.  include "../../mk/krb5.buildlink3.mk"
.endif
.endif # POSTGRESQL13_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql13-client
