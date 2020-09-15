# $NetBSD: hacks.mk,v 1.1 2020/09/15 16:16:29 he Exp $

.if !defined(LIBLLVM_HACKS_MK)
LIBLLVM_HACKS_MK=	defined

# [ Tue Sep 15 07:21:13 CEST 2020 : he ]
# On NetBSD/powerpc, enable -mlongcall, to avoid relocation overflows
.if ${MACHINE_ARCH} == "powerpc"
CFLAGS+=	-mlongcall
CXXFLAGS+=	-mlongcall
.endif

.endif	# LIBLLVM_HACKS_MK
