# $NetBSD: buildlink3.mk,v 1.5 2022/06/28 11:31:32 wiz Exp $

BUILDLINK_TREE+=	postgresql10-client

.if !defined(POSTGRESQL10_CLIENT_BUILDLINK3_MK)
POSTGRESQL10_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql10-client+=	postgresql10-client>=10.0
BUILDLINK_ABI_DEPENDS.postgresql10-client+=	postgresql10-client>=10.21nb1
BUILDLINK_PKGSRCDIR.postgresql10-client?=	../../databases/postgresql10-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql10-client=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql10-client+=	bin/pg_config

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "SunOS"
.include "../../devel/ossp-uuid/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # POSTGRESQL10_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql10-client
