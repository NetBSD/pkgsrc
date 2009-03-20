# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:13 joerg Exp $

BUILDLINK_TREE+=	gdbada

.if !defined(GDBADA_BUILDLINK3_MK)
GDBADA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdbada+=	gdbada>=5.3
BUILDLINK_ABI_DEPENDS.gdbada+=	gdbada>=6.3nb1
BUILDLINK_PKGSRCDIR.gdbada?=	../../devel/gdbada

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # GDBADA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdbada
