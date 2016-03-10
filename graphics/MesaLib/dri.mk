# $NetBSD: dri.mk,v 1.16 2016/03/10 05:29:56 tnn Exp $
#
# Currently, this is for convenience only.
#
.if !defined(DRI_MK)
DRI_MK=		# defined

.  if !defined(USE_BUILTIN.MesaLib)
CHECK_BUILTIN.MesaLib:=	yes
.    include "../../graphics/MesaLib/builtin.mk"
CHECK_BUILTIN.MesaLib:=	no
.  endif

.  if !empty(USE_BUILTIN.MesaLib:M[Nn][Oo])
BUILDLINK_API_DEPENDS.dri2proto+=	dri2proto>=2.1
BUILDLINK_API_DEPENDS.glproto+=		glproto>=1.4.11
.    if ${OPSYS} != "Darwin"
BUILDLINK_API_DEPENDS.libdrm+=		libdrm>=2.4.60
.    endif
.    if ${OPSYS} == "Linux"
BUILDLINK_API_DEPENDS.libxcb+=	libxcb>=1.9.3
.    endif
.  endif
.  include "../../textproc/expat/buildlink3.mk"
.  include "../../x11/dri2proto/buildlink3.mk"
# XXX these do not have builtin.mk
.  if ${X11_TYPE} == "modular"
.    include "../../x11/dri3proto/buildlink3.mk"
.    include "../../x11/libxshmfence/buildlink3.mk"
.    include "../../x11/presentproto/buildlink3.mk"
.  endif
.  include "../../x11/glproto/buildlink3.mk"
.  include "../../x11/libXdamage/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.  include "../../x11/libXxf86vm/buildlink3.mk"
.  if ${OPSYS} != "Darwin"
.    include "../../x11/libdrm/buildlink3.mk"
.  endif
.  include "../../x11/xf86driproto/buildlink3.mk"
.  include "../../x11/xf86vidmodeproto/buildlink3.mk"
.  if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
.    include "../../devel/libdevq/buildlink3.mk"
.  endif
.endif
