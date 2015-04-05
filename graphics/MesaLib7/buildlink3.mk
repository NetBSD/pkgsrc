# $NetBSD: buildlink3.mk,v 1.1 2015/04/05 17:01:37 tnn Exp $

BUILDLINK_TREE+=	MesaLib7

.if !defined(MESALIB7_BUILDLINK3_MK)
MESALIB7_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.MesaLib7+=	MesaLib7>=7.11.2
BUILDLINK_PKGSRCDIR.MesaLib7?=		../../graphics/MesaLib7

.include "../../mk/bsd.fast.prefs.mk"

# See <http://developer.apple.com/qa/qa2007/qa1567.html>.
.if !empty(MACHINE_PLATFORM:MDarwin-[9].*-*)
BUILDLINK_LDFLAGS.MesaLib7+=	-Wl,-dylib_file,/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib:/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib
.endif

pkgbase:= MesaLib7
.include "../../mk/pkg-build-options.mk"

.if ${X11_TYPE} == "native" && ${OPSYS} != "Cygwin" && exists(${X11BASE}/lib/pkgconfig/dri.pc)
PKG_BUILD_OPTIONS.MesaLib7+=	dri
.endif

.if !empty(PKG_BUILD_OPTIONS.MesaLib7:Mdri)
.  include "../../graphics/MesaLib/dri.mk"
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-[12].*)
.include "../../devel/pthread-stublib/buildlink3.mk"
.endif

.include "../../x11/libXext/buildlink3.mk"
.endif # MESALIB7_BUILDLINK3_MK

BUILDLINK_TREE+=	-MesaLib7
