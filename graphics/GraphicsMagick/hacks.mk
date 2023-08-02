# $NetBSD: hacks.mk,v 1.2 2023/08/02 07:57:36 adam Exp $

.if !defined(GRAPHICSMAGICK_HACKS_MK)
GRAPHICSMAGICK_HACKS_MK=	# defined

# Gain 2-3X speedup by working around GCC optimisation bug
# http://gcc.gnu.org/bugzilla/show_bug.cgi?id=53967
.include "../../mk/compiler.mk"
.if ${CC_VERSION:Mgcc-4.*} && ${MACHINE_ARCH} == "x86_64"
PKG_HACKS+=	frename-registers
CFLAGS+=	-frename-registers
.endif

.endif
