# $NetBSD: buildlink3.mk,v 1.5 2009/12/09 19:01:05 drochner Exp $

BUILDLINK_TREE+=	brasero

.if !defined(BRASERO_BUILDLINK3_MK)
BRASERO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.brasero+=	brasero>=2.26.0
BUILDLINK_ABI_DEPENDS.brasero?=	brasero>=2.26.3nb1
BUILDLINK_PKGSRCDIR.brasero?=	../../sysutils/brasero

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # BRASERO_BUILDLINK3_MK

BUILDLINK_TREE+=	-brasero
