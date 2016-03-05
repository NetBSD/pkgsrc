# $NetBSD: buildlink3.mk,v 1.4 2016/03/05 11:27:43 jperkin Exp $

BUILDLINK_TREE+=	postgresql91-client

.if !defined(POSTGRESQL91_CLIENT_BUILDLINK3_MK)
POSTGRESQL91_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql91-client+=	postgresql91-client>=9.1.0
BUILDLINK_ABI_DEPENDS.postgresql91-client+=	postgresql91-client>=9.1.20nb1
BUILDLINK_PKGSRCDIR.postgresql91-client?=	../../databases/postgresql91-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql91-client=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql91-client+=	bin/pg_config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # POSTGRESQL91_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql91-client
