# $NetBSD: mipspro-ucode.mk,v 1.2 2004/02/18 13:32:38 jlam Exp $

.if !defined(COMPILER_MIPSPRO_UCODE_MK)
COMPILER_MIPSPRO_UCODE_MK=	defined

.include "../../mk/bsd.prefs.mk"

CC_VERSION?=	MIPSpro Compilers: Version 4.x (ucode)

.include "../../mk/compilers/mipspro.mk"

.endif	# COMPILER_MIPSPRO_UCODE_MK
