# $NetBSD: buildlink3.mk,v 1.14 2020/11/19 02:57:11 gutteridge Exp $

BUILDLINK_TREE+=	gdbm

.if !defined(GDBM_BUILDLINK3_MK)
GDBM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdbm+=	gdbm>=1.8.3
BUILDLINK_ABI_DEPENDS.gdbm+=	gdbm>=1.18.1
BUILDLINK_PKGSRCDIR.gdbm?=	../../databases/gdbm

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # GDBM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdbm
