# $NetBSD: hacks.mk,v 1.1 2018/04/25 22:39:02 kamil Exp $

.if !defined(VLC2_HACKS_MK)
VLC2_HACKS_MK=		# empty

# vlc_atomic.h rightly assumes "uses clang (support for C11)" implies
# "ships stdatomic.h" but for us this is not yet the case.
# This hack should be removed when -current has stdatomic.h.
.if	${OPSYS} == "NetBSD" &&		\
	exists(/usr/bin/clang) &&	\
	!exists(/usr/include/stdatomic.h)
CPPFLAGS+=		-D__STDC_NO_ATOMICS__
.endif

.endif
