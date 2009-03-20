# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:05 joerg Exp $

BUILDLINK_TREE+=	gdbm

.if !defined(GDBM_BUILDLINK3_MK)
GDBM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdbm+=	gdbm>=1.8.3
BUILDLINK_ABI_DEPENDS.gdbm+=	gdbm>=1.8.3nb1
BUILDLINK_PKGSRCDIR.gdbm?=	../../databases/gdbm
.endif # GDBM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdbm
