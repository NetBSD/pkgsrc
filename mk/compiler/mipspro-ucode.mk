# $NetBSD: mipspro-ucode.mk,v 1.1 2004/02/18 11:18:43 jlam Exp $

.if !defined(COMPILER_MIPSPRO_UCODE_MK)
COMPILER_MIPSPRO_UCODE_MK=	one

CC_VERSION=	MIPSpro Compilers: Version 4.x (ucode)
.  include "../../mk/compilers/mipspro.mk"
.endif	# COMPILER_MIPSPRO_UCODE_MK

# The following section is included only if we're not being included by
# bsd.prefs.mk.
#
.if empty(BSD_PREFS_MK)
.  if empty(COMPILER_MIPSPRO_UCODE_MK:Mtwo)
COMPILER_MIPSPRO_UCODE_MK+=	two
.    include "../../mk/compilers/mipspro.mk"
.  endif # COMPILER_MIPSPRO_UCODE_MK
.endif	 # BSD_PREFS_MK
