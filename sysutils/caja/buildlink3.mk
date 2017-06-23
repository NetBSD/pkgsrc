# $NetBSD: buildlink3.mk,v 1.5 2017/06/23 17:06:33 youri Exp $
#

BUILDLINK_TREE+=	caja

.if !defined(CAJA_BUILDLINK3_MK)
CAJA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.caja+=	caja>=1.8.2
BUILDLINK_ABI_DEPENDS.caja+=	caja>=1.14.1nb3
BUILDLINK_PKGSRCDIR.caja?=	../../sysutils/caja

.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../devel/exempi/buildlink3.mk"
.endif	# CAJA_BUILDLINK3_MK

BUILDLINK_TREE+=	-caja
