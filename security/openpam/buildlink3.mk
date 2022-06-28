# $NetBSD: buildlink3.mk,v 1.6 2022/06/28 11:35:38 wiz Exp $

BUILDLINK_TREE+=	openpam

.if !defined(OPENPAM_BUILDLINK3_MK)
OPENPAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openpam+=	openpam>=20040210
BUILDLINK_ABI_DEPENDS.openpam?=	openpam>=20190224nb4
BUILDLINK_PKGSRCDIR.openpam?=	../../security/openpam

.include "../../mk/dlopen.buildlink3.mk"
.endif # OPENPAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-openpam
