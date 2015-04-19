# $NetBSD: buildlink3.mk,v 1.1 2015/04/19 23:45:06 rodent Exp $

BUILDLINK_TREE+=	sratom

.if !defined(SRATOM_BUILDLINK3_MK)
SRATOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sratom+=	sratom>=0.4.6
BUILDLINK_PKGSRCDIR.sratom?=	../../converters/sratom

.include "../../textproc/sord/buildlink3.mk"
.include "../../textproc/serd/buildlink3.mk"
.endif	# SRATOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-sratom
