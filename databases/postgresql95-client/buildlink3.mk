# $NetBSD: buildlink3.mk,v 1.5 2021/03/18 15:04:56 adam Exp $

BUILDLINK_TREE+=	postgresql95-client

.if !defined(POSTGRESQL95_CLIENT_BUILDLINK3_MK)
POSTGRESQL95_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql95-client+=	postgresql95-client>=9.5.1
BUILDLINK_ABI_DEPENDS.postgresql95-client+=	postgresql95-client>=9.5.24nb1
BUILDLINK_PKGSRCDIR.postgresql95-client?=	../../databases/postgresql95-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql95-client=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql95-client+=	bin/pg_config

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "SunOS"
.include "../../devel/ossp-uuid/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # POSTGRESQL95_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql95-client
