# $NetBSD: avoid-duplicate.mk,v 1.3 2022/03/26 19:48:21 nia Exp $

BUILTIN_PKG=		${X11_BUILTIN_NAME}

#.include "${.INCLUDEDFROMDIR}/builtin.mk"

#.if ${X11_TYPE} == "native" && ${USE_BUILTIN.${X11_BUILTIN_NAME}} == "yes"
#PKG_SKIP_REASON+=	"Package set is using native X11 component"
#.endif
