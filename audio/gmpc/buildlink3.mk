# $NetBSD: buildlink3.mk,v 1.47 2024/11/17 07:15:31 wiz Exp $

BUILDLINK_TREE+=	gmpc

.if !defined(GMPC_BUILDLINK3_MK)
GMPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmpc+=	gmpc>=0.20.0
BUILDLINK_ABI_DEPENDS.gmpc+=	gmpc>=11.8.16nb53
BUILDLINK_PKGSRCDIR.gmpc?=	../../audio/gmpc

.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# GMPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmpc
