# $NetBSD: hacks.mk,v 1.1 2020/09/08 06:33:47 he Exp $

.if !defined(WKHTMLTOPDF_HACKS_MK)
WKHTMLTOPDF_HACKS_MK=    defined

# [Mon Sep  7 21:12:45 CEST 2020 : he]
# On NetBSD/powerpc, we get relocation truncated to fit: R_PPC_PLTREL24
# with default build options.
.if !empty(MACHINE_ARCH:Mpowerpc*) 
CFLAGS+=	-mlongcall
CXXFLAGS+=	-mlongcall
PKG_HACKS+=	powerpc-longcall
.endif 

.endif  # WKHTMLTOPDF_HACKS_MK
