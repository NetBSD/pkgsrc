# $NetBSD: buildlink3.mk,v 1.2 2020/01/18 21:48:02 jperkin Exp $

BUILDLINK_TREE+=	postgresql96-client

.if !defined(POSTGRESQL96_CLIENT_BUILDLINK3_MK)
POSTGRESQL96_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql96-client+=	postgresql96-client>=9.6.1
BUILDLINK_ABI_DEPENDS.postgresql96-client+=	postgresql96-client>=9.6.16nb1
BUILDLINK_PKGSRCDIR.postgresql96-client?=	../../databases/postgresql96-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql96-client=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql96-client+=	bin/pg_config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # POSTGRESQL96_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql96-client
