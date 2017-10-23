# $NetBSD: buildlink3.mk,v 1.1 2017/10/23 20:33:49 adam Exp $

BUILDLINK_TREE+=	postgresql10-client

.if !defined(POSTGRESQL10_CLIENT_BUILDLINK3_MK)
POSTGRESQL10_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql10-client+=	postgresql10-client>=10.0
BUILDLINK_ABI_DEPENDS.postgresql10-client+=	postgresql10-client>=10.0
BUILDLINK_PKGSRCDIR.postgresql10-client?=	../../databases/postgresql10-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql10-client=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql10-client+=	bin/pg_config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # POSTGRESQL10_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql10-client
