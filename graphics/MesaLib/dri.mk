# $NetBSD: dri.mk,v 1.2 2009/06/05 11:10:35 wiz Exp $
#
# Currently, this is for convenience only.
#
.if !defined(DRI_MK)
DRI_MK=		# defined

.  include "../../textproc/expat/buildlink3.mk"
.  include "../../x11/dri2proto/buildlink3.mk"
.  include "../../x11/glproto/buildlink3.mk"
.  include "../../x11/libXdamage/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.  include "../../x11/libdrm/buildlink3.mk"
.  include "../../x11/libXxf86vm/buildlink3.mk"
.  include "../../x11/xf86driproto/buildlink3.mk"
.  include "../../x11/xf86vidmodeproto/buildlink3.mk"
.endif
