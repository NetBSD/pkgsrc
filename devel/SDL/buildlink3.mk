# $NetBSD: buildlink3.mk,v 1.29 2008/05/06 06:36:44 bjs Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SDL_BUILDLINK3_MK:=	${SDL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	SDL
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NSDL}
BUILDLINK_PACKAGES+=	SDL
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}SDL

.if !empty(SDL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.SDL+=	SDL>=1.2.5nb5
BUILDLINK_ABI_DEPENDS.SDL+=	SDL>=1.2.10
BUILDLINK_PKGSRCDIR.SDL?=	../../devel/SDL
.endif	# SDL_BUILDLINK3_MK

PTHREAD_OPTS+=	require

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "IRIX" && ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

pkgbase := SDL
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.SDL:Maalib)
.include "../../graphics/aalib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.SDL:Mnas)
.include "../../audio/nas/buildlink3.mk"
.endif

.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
