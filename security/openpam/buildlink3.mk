# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:25:21 joerg Exp $

BUILDLINK_TREE+=	openpam

.if !defined(OPENPAM_BUILDLINK3_MK)
OPENPAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openpam+=	openpam>=20040210
BUILDLINK_PKGSRCDIR.openpam?=	../../security/openpam

.include "../../mk/dlopen.buildlink3.mk"
.endif # OPENPAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-openpam
