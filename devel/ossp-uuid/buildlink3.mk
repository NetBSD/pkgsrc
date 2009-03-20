# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:25 joerg Exp $

BUILDLINK_TREE+=	ossp-uuid

.if !defined(OSSP_UUID_BUILDLINK3_MK)
OSSP_UUID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ossp-uuid+=	ossp-uuid>=1.6.0
BUILDLINK_ABI_DEPENDS.ossp-uuid+=	ossp-uuid>=1.6.2
BUILDLINK_PKGSRCDIR.ossp-uuid?=		../../devel/ossp-uuid
.endif # OSSP_UUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-ossp-uuid
