# $NetBSD: hacks.mk,v 1.1 2014/08/14 15:23:59 jperkin Exp $

.if !defined(GRAPHICSMAGICK_HACKS_MK)
GRAPHICSMAGICK_HACKS_MK=	# defined

# Gain 2-3X speedup by working around GCC optimisation bug
# http://gcc.gnu.org/bugzilla/show_bug.cgi?id=53967
.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-4.*) && ${MACHINE_ARCH} == "x86_64"
PKG_HACKS+=	frename-registers
CFLAGS+=	-frename-registers
.endif

.endif
