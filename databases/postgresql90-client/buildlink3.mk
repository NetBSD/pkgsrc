# $NetBSD: buildlink3.mk,v 1.8 2014/02/12 23:17:41 tron Exp $

BUILDLINK_TREE+=	postgresql90-client

.if !defined(POSTGRESQL90_CLIENT_BUILDLINK3_MK)
POSTGRESQL90_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql90-client+=	postgresql90-client>=9.0.0
BUILDLINK_ABI_DEPENDS.postgresql90-client+=	postgresql90-client>=9.0.15nb1
BUILDLINK_PKGSRCDIR.postgresql90-client?=	../../databases/postgresql90-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql90-client=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql90-client+=	bin/pg_config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # POSTGRESQL90_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql90-client
