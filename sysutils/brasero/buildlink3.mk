# $NetBSD: buildlink3.mk,v 1.6 2010/06/13 22:45:21 wiz Exp $

BUILDLINK_TREE+=	brasero

.if !defined(BRASERO_BUILDLINK3_MK)
BRASERO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.brasero+=	brasero>=2.26.0
BUILDLINK_ABI_DEPENDS.brasero?=	brasero>=2.28.3nb3
BUILDLINK_PKGSRCDIR.brasero?=	../../sysutils/brasero

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # BRASERO_BUILDLINK3_MK

BUILDLINK_TREE+=	-brasero
