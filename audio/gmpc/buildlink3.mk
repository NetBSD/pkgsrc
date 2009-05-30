# $NetBSD: buildlink3.mk,v 1.1 2009/05/30 01:25:19 obache Exp $

BUILDLINK_TREE+=	gmpc

.if !defined(GMPC_BUILDLINK3_MK)
GMPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmpc+=	gmpc>=0.18.0
BUILDLINK_PKGSRCDIR.gmpc?=	../../audio/gmpc

.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# GMPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmpc
