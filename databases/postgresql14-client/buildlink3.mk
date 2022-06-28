# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:31:36 wiz Exp $

BUILDLINK_TREE+=	postgresql14-client

.if !defined(POSTGRESQL14_CLIENT_BUILDLINK3_MK)
POSTGRESQL14_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.postgresql14-client+=	postgresql14-client>=14.0
BUILDLINK_ABI_DEPENDS.postgresql14-client+=	postgresql14-client>=14.4nb1
BUILDLINK_PKGSRCDIR.postgresql14-client?=	../../databases/postgresql14-client

# This variable contains the libraries need to link most clients.
BUILDLINK_LDADD.postgresql14-client=	-lpq ${BUILDLINK_LDADD.gettext}
BUILDLINK_FILES.postgresql14-client+=	bin/pg_config

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "SunOS"
.include "../../devel/ossp-uuid/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # POSTGRESQL14_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-postgresql14-client
