# $NetBSD: buildlink3.mk,v 1.6 2020/03/08 16:48:10 wiz Exp $
#

BUILDLINK_TREE+=	caja

.if !defined(CAJA_BUILDLINK3_MK)
CAJA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.caja+=	caja>=1.8.2
BUILDLINK_ABI_DEPENDS.caja+=	caja>=1.22.3nb1
BUILDLINK_PKGSRCDIR.caja?=	../../sysutils/caja

.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../devel/exempi/buildlink3.mk"
.endif	# CAJA_BUILDLINK3_MK

BUILDLINK_TREE+=	-caja
