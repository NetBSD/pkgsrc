# $NetBSD: gcc.buildlink2.mk,v 1.2.4.3 2003/08/23 09:45:55 jlam Exp $
#
# USE_GCC2
#	If defined, use gcc from lang/gcc.
# USE_GCC3
#	If defined, use gcc3 from lang/gcc3.
#

.if !defined(GCC_BUILDLINK2_MK)
GCC_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

.if defined(USE_GCC3) && empty(PKGPATH:Mlang/gcc3) && empty(_PKGSRC_DEPS:Mgcc-3.*)
.  include "../lang/gcc3/buildlink2.mk"
.elif defined(USE_GCC2) && empty(PKGPATH:Mlang/gcc) && empty(_PKGSRC_DEPS:Mgcc-2.*)
.  include "../lang/gcc/buildlink2.mk"
.endif

.endif	# GCC_BUILDLINK2_MK
