# $NetBSD: buildlink3.mk,v 1.40 2023/01/29 21:14:22 ryoon Exp $

BUILDLINK_TREE+=	gmpc

.if !defined(GMPC_BUILDLINK3_MK)
GMPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmpc+=	gmpc>=0.20.0
BUILDLINK_ABI_DEPENDS.gmpc+=	gmpc>=11.8.16nb41
BUILDLINK_PKGSRCDIR.gmpc?=	../../audio/gmpc
BUILDLINK_DEPMETHOD.gmpc?=	build

.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# GMPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmpc
