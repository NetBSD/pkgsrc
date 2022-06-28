# $NetBSD: buildlink3.mk,v 1.5 2022/06/28 11:31:33 wiz Exp $

BUILDLINK_TREE+=	postgresql11-client

.if !defined(POSTGRESQL11_CLIENT_BUILDLINK3_MK)
POSTGRESQL11_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql11-client+=	postgresql11-client>=11.0
BUILDLINK_ABI_DEPENDS.postgresql11-client+=	postgresql11-client>=11.16nb1
BUILDLINK_PKGSRCDIR.postgresql11-client?=	../../databases/postgresql11-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql11-client=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql11-client+=	bin/pg_config

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "SunOS"
.include "../../devel/ossp-uuid/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # POSTGRESQL11_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql11-client
