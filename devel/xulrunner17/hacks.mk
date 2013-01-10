# $NetBSD: hacks.mk,v 1.1 2013/01/10 16:17:09 ryoon Exp $

.if !defined(XULRUNNER_HACKS_MK)
XULRUNNER_HACKS_MK=	defined

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/compiler.mk"

# PR pkg/44912: gcc generates unaligned SSE2 references
.if !empty(PKGSRC_COMPILER:Mgcc) && !empty(CC_VERSION:Mgcc-4.[0-3]*) && (!empty(MACHINE_PLATFORM:M*-*-i386) || !empty(MACHINE_PLATFORM:M*-*-x86_64))
PKG_HACKS+=		optimization
BUILDLINK_TRANSFORM+=	rm:-march=[-_A-Za-z0-9]*
SUBST_CLASSES+=		opt-hack
SUBST_STAGE.opt-hack=	post-patch
SUBST_MESSAGE.opt-hack=	Working around optimizer bug.
SUBST_FILES.opt-hack=	${MOZILLA_DIR}gfx/skia/Makefile.in
SUBST_SED.opt-hack=	-e '/SkBlitRow_opts_SSE2/s/-msse2/-msse2 -O0/'
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-return-type-c-linkage
.endif

.endif	# XULRUNNER_HACKS_MK
