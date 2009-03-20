# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:23:51 joerg Exp $

BUILDLINK_TREE+=	szip

.if !defined(SZIP_BUILDLINK3_MK)
SZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.szip+=	szip>=2.0
BUILDLINK_PKGSRCDIR.szip?=	../../archivers/szip
.endif # SZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-szip
