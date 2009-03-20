# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:07 joerg Exp $

BUILDLINK_TREE+=	sdbm

.if !defined(SDBM_BUILDLINK3_MK)
SDBM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sdbm+=	sdbm>=90.12.1
BUILDLINK_PKGSRCDIR.sdbm?=	../../databases/sdbm
.endif # SDBM_BUILDLINK3_MK

BUILDLINK_TREE+=	-sdbm
