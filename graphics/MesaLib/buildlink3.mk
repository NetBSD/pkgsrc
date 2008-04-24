# $NetBSD: buildlink3.mk,v 1.44 2008/04/24 07:40:24 bjs Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MESALIB_BUILDLINK3_MK:=	${MESALIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	MesaLib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NMesaLib}
BUILDLINK_PACKAGES+=	MesaLib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}MesaLib

.if !empty(MESALIB_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=3.4.2
BUILDLINK_ABI_DEPENDS.MesaLib+=	MesaLib>=6.4.1nb1
BUILDLINK_ABI_DEPENDS.MesaLib+= MesaLib>=7.0.3
BUILDLINK_PKGSRCDIR.MesaLib?=	../../graphics/MesaLib

.include "../../mk/bsd.fast.prefs.mk"

# See <http://developer.apple.com/qa/qa2007/qa1567.html>.
.if !empty(MACHINE_PLATFORM:MDarwin-[9].*-*)
BUILDLINK_LDFLAGS.MesaLib+=	-Wl,-dylib_file -Wl,/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib:/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib
.endif

pkgbase:= MesaLib
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.MesaLib:Mdri)
.  include "../../graphics/MesaLib/dri.mk"
.endif

.endif	# MESALIB_BUILDLINK3_MK

.if !empty(MACHINE_PLATFORM:MNetBSD-[12].*)
.include "../../devel/pthread-stublib/buildlink3.mk"
.endif

.include "../../x11/libXext/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
