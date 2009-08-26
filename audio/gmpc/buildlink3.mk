# $NetBSD: buildlink3.mk,v 1.3 2009/08/26 19:56:56 sno Exp $

BUILDLINK_TREE+=	gmpc

.if !defined(GMPC_BUILDLINK3_MK)
GMPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmpc+=	gmpc>=0.18.0
BUILDLINK_ABI_DEPENDS.gmpc?=	gmpc>=0.18.0nb1
BUILDLINK_PKGSRCDIR.gmpc?=	../../audio/gmpc
BUILDLINK_DEPMETHOD.gmpc?=	build

.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# GMPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmpc
