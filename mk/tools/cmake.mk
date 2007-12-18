# $NetBSD: cmake.mk,v 1.1 2007/12/18 10:18:44 markd Exp $
#

# This file needs to be included before replace.mk as it modifies the
# USE_TOOLS variables that are used by replace.mk.
#
.if defined(USE_CMAKE)
USE_TOOLS+=	cmake cpack
.endif

# cmake and cpack imply each other
.if !empty(USE_TOOLS:Mcmake) || !empty(USE_TOOLS:Mcpack)
USE_TOOLS+=	cmake cpack
.endif
