# $NetBSD: libm.mk,v 1.2 2019/11/03 19:04:04 rillig Exp $
#
# XXX I took this from jslibmath.h.  If this is not correct, please feel
# 	free to change it.  Our lang/spidermonkey package never uses
# 	the Sun math library, and I'm not sure if this is correct.
#
.include "../../mk/bsd.fast.prefs.mk"

JS_FDLIBM_PLATFORMS=	Linux-*-* IRIX-*-* SunOS-*-* \
			Solaris-*-* AIX-*-* HPUX-*-*

JS_FDLIBM_MATH_REQUESTED?=	no
.for plat in ${JS_FDLIBM_PLATFORMS}
.  if !empty(MACHINE_PLATFORM:M${plat})
JS_FDLIBM_MATH_REQUESTED=	yes
.  endif
.endfor

.if !empty(JS_FDLIBM_MATH_REQUESTED:M[Yy][Ee][Ss])
CPPFLAGS+=	-DJS_FDLIBM_MATH_REQUESTED=1
.else
CPPFLAGS+=	-DJS_FDLIBM_MATH_REQUESTED=0
.endif
