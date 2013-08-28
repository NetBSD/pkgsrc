# $NetBSD: dri.mk,v 1.6.10.1 2013/08/28 05:40:18 spz Exp $
#
# Currently, this is for convenience only.
#
.if !defined(DRI_MK)
DRI_MK=		# defined

.  include "../../textproc/expat/buildlink3.mk"
.  include "../../x11/dri2proto/buildlink3.mk"
BUILDLINK_API_DEPENDS.glproto+=	glproto>=1.4.11
.  include "../../x11/glproto/buildlink3.mk"
.  include "../../x11/libXdamage/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.  include "../../x11/libdrm/buildlink3.mk"
.  include "../../x11/libXxf86vm/buildlink3.mk"
.  include "../../x11/xf86driproto/buildlink3.mk"
.  include "../../x11/xf86vidmodeproto/buildlink3.mk"
.endif
