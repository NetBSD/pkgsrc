# $NetBSD: buildlink3.mk,v 1.42 2007/12/05 21:42:18 tron Exp $

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
BUILDLINK_PKGSRCDIR.MesaLib?=	../../graphics/MesaLib

.if !defined(BUILDING_MESA)
BUILDLINK_CPPFLAGS.MesaLib=	-DGLX_GLXEXT_LEGACY
.endif

# See <http://developer.apple.com/qa/qa2007/qa1567.html>.
.if !empty(MACHINE_PLATFORM:MDarwin-[9].*-*)
BUILDLINK_LDFLAGS.MesaLib+=	-Wl,-dylib_file -Wl,/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib:/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib
.endif

BUILDLINK_TRANSFORM+=		l:MesaGL:GL

.endif	# MESALIB_BUILDLINK3_MK

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-[12].*)
.include "../../devel/pthread-stublib/buildlink3.mk"
.endif

.include "../../x11/libXext/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
