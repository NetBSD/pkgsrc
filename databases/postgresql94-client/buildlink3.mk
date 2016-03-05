# $NetBSD: buildlink3.mk,v 1.2 2016/03/05 11:27:43 jperkin Exp $

BUILDLINK_TREE+=	postgresql94-client

.if !defined(POSTGRESQL94_CLIENT_BUILDLINK3_MK)
POSTGRESQL94_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql94-client+=	postgresql94-client>=9.4.0
BUILDLINK_ABI_DEPENDS.postgresql94-client+=	postgresql94-client>=9.4.6nb1
BUILDLINK_PKGSRCDIR.postgresql94-client?=	../../databases/postgresql94-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql94-client=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql94-client+=	bin/pg_config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # POSTGRESQL94_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql94-client
