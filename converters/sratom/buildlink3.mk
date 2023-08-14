# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:23:58 wiz Exp $

BUILDLINK_TREE+=	sratom

.if !defined(SRATOM_BUILDLINK3_MK)
SRATOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sratom+=	sratom>=0.4.6
BUILDLINK_ABI_DEPENDS.sratom?=	sratom>=0.6.10nb5
BUILDLINK_PKGSRCDIR.sratom?=	../../converters/sratom

.include "../../textproc/sord/buildlink3.mk"
.include "../../textproc/serd/buildlink3.mk"
.endif	# SRATOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-sratom
