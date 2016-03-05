# $NetBSD: buildlink3.mk,v 1.3 2016/03/05 11:27:43 jperkin Exp $

BUILDLINK_TREE+=	postgresql93-client

.if !defined(POSTGRESQL93_CLIENT_BUILDLINK3_MK)
POSTGRESQL93_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql93-client+=	postgresql93-client>=9.3.0
BUILDLINK_ABI_DEPENDS.postgresql93-client+=	postgresql93-client>=9.3.11nb1
BUILDLINK_PKGSRCDIR.postgresql93-client?=	../../databases/postgresql93-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql93-client=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql93-client+=	bin/pg_config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # POSTGRESQL93_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql93-client
