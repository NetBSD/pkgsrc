# $NetBSD: buildlink3.mk,v 1.1 2012/10/05 21:03:10 adam Exp $

BUILDLINK_TREE+=	postgresql92-client

.if !defined(POSTGRESQL92_CLIENT_BUILDLINK3_MK)
POSTGRESQL92_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql92-client+=	postgresql92-client>=9.2.0
BUILDLINK_ABI_DEPENDS.postgresql92-client+=	postgresql92-client>=9.2.0
BUILDLINK_PKGSRCDIR.postgresql92-client?=	../../databases/postgresql92-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql92-client=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql92-client+=	bin/pg_config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # POSTGRESQL92_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql92-client
