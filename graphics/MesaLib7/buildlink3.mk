# $NetBSD: buildlink3.mk,v 1.4 2018/09/01 20:46:07 bsiegert Exp $

BUILDLINK_TREE+=	MesaLib7

.if !defined(MESALIB7_BUILDLINK3_MK)
MESALIB7_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.MesaLib7+=	MesaLib7>=7.11.2
BUILDLINK_PKGSRCDIR.MesaLib7?=		../../graphics/MesaLib7
BUILDLINK_FNAME_TRANSFORM.MesaLib7+=	-e 's|MesaLib7/||'
BUILDLINK_RPATHDIRS+=			MesaLib7/lib

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

.include "../../x11/libXext/buildlink3.mk"
.endif # MESALIB7_BUILDLINK3_MK

BUILDLINK_TREE+=	-MesaLib7
