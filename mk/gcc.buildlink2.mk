# $NetBSD: gcc.buildlink2.mk,v 1.1 2003/05/27 07:01:57 grant Exp $
#
# USE_GCC3
#	If defined, use gcc3 from lang/gcc3.
#

.if !defined(GCC_BUILDLINK2_MK)
GCC_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if defined(USE_GCC3)
.  include "../lang/gcc3/buildlink2.mk"
.else
.  include "../lang/gcc/buildlink2.mk"
.endif

.endif	# GCC_BUILDLINK2_MK
