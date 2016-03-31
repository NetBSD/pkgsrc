# $NetBSD: buildlink3.mk,v 1.4 2016/03/31 20:25:23 fhajny Exp $

BUILDLINK_TREE+=	ossp-uuid

.if !defined(OSSP_UUID_BUILDLINK3_MK)
OSSP_UUID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ossp-uuid+=	ossp-uuid>=1.6.0
BUILDLINK_ABI_DEPENDS.ossp-uuid+=	ossp-uuid>=1.6.2
BUILDLINK_PKGSRCDIR.ossp-uuid?=		../../devel/ossp-uuid

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDLINK_LDADD.ossp-uuid+=	-lnsl -lsocket
BUILDLINK_LDFLAGS.ossp-uuid?=	${BUILDLINK_LDADD.ossp-uuid}
.endif
.endif # OSSP_UUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-ossp-uuid
