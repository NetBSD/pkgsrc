# $NetBSD: buildlink3.mk,v 1.46 2024/10/20 14:03:21 wiz Exp $

BUILDLINK_TREE+=	gmpc

.if !defined(GMPC_BUILDLINK3_MK)
GMPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmpc+=	gmpc>=0.20.0
BUILDLINK_ABI_DEPENDS.gmpc+=	gmpc>=11.8.16nb49
BUILDLINK_PKGSRCDIR.gmpc?=	../../audio/gmpc

.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# GMPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmpc
