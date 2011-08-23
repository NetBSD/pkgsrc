# $NetBSD: buildlink3.mk,v 1.9 2011/08/23 13:06:48 obache Exp $

BUILDLINK_TREE+=	gdbm

.if !defined(GDBM_BUILDLINK3_MK)
GDBM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdbm+=	gdbm>=1.8.3
BUILDLINK_ABI_DEPENDS.gdbm+=	gdbm>=1.9.1
BUILDLINK_PKGSRCDIR.gdbm?=	../../databases/gdbm
.endif # GDBM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdbm
