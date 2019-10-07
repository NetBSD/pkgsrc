# $NetBSD: buildlink3.mk,v 1.1 2019/10/07 19:21:48 adam Exp $

BUILDLINK_TREE+=	postgresql12-client

.if !defined(POSTGRESQL12_CLIENT_BUILDLINK3_MK)
POSTGRESQL12_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql12-client+=	postgresql12-client>=12.0
BUILDLINK_ABI_DEPENDS.postgresql12-client+=	postgresql12-client>=12.0
BUILDLINK_PKGSRCDIR.postgresql12-client?=	../../databases/postgresql12-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql12-client=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql12-client+=	bin/pg_config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # POSTGRESQL12_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql12-client
