# $NetBSD: buildlink3.mk,v 1.35 2015/06/30 10:02:21 ryoon Exp $

BUILDLINK_TREE+=	gd

.if !defined(GD_BUILDLINK3_MK)
GD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gd+=	gd>=2.0.15nb1
BUILDLINK_ABI_DEPENDS.gd+=	gd>=2.1.0nb4
BUILDLINK_PKGSRCDIR.gd?=	../../graphics/gd

.include "../../mk/bsd.fast.prefs.mk"

_GD_PRE_LIBVPX_OPTION!= \
	if ${PKG_INFO} -qe 'gd<2.1.0nb1'; then	\
		${ECHO} yes;			\
	else					\
		${ECHO} no;			\
	fi

pkgbase := gd
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gd:Mx11)
.include "../../x11/libXpm/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.if ${_GD_PRE_LIBVPX_OPTION} == "yes" || !empty(PKG_BUILD_OPTIONS.gd:Mlibvpx)
.include "../../multimedia/libvpx/buildlink3.mk"
.endif
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gd
