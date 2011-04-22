# $NetBSD: buildlink3.mk,v 1.9 2011/04/22 13:42:03 obache Exp $

BUILDLINK_TREE+=	gdbada

.if !defined(GDBADA_BUILDLINK3_MK)
GDBADA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdbada+=	gdbada>=5.3
BUILDLINK_ABI_DEPENDS.gdbada+=	gdbada>=6.3nb3
BUILDLINK_PKGSRCDIR.gdbada?=	../../devel/gdbada

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # GDBADA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdbada
