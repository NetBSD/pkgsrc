# $NetBSD: buildlink3.mk,v 1.10 2012/01/24 08:26:23 sbd Exp $

BUILDLINK_TREE+=	gdbm

.if !defined(GDBM_BUILDLINK3_MK)
GDBM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdbm+=	gdbm>=1.8.3
BUILDLINK_ABI_DEPENDS.gdbm+=	gdbm>=1.9.1nb3
BUILDLINK_PKGSRCDIR.gdbm?=	../../databases/gdbm

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # GDBM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdbm
