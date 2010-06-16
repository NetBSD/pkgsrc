# $NetBSD: dlopen.builtin.mk,v 1.21 2010/06/16 19:57:08 drochner Exp $

BUILTIN_PKG:=	dl

BUILTIN_FIND_LIBS:=		dl
BUILTIN_FIND_FILES_VAR:=	H_DL
BUILTIN_FIND_FILES.H_DL=	/usr/include/dlfcn.h			\
				/opt/gcc.3.3/include/dlfcn.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.dl)
IS_BUILTIN.dl=	no
.  if empty(H_DL:M${LOCALBASE}/*) && exists(${H_DL})
IS_BUILTIN.dl=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.dl

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
#
# We ignore the value of PREFER_PKGSRC and PREFER_NATIVE because for
# every platform except for Darwin-[56].*, we can only use the built-in
# dynamic linker functions, so USE_BUILTIN.dl must match IS_BUILTIN.dl.
#
.if !defined(USE_BUILTIN.dl)
USE_BUILTIN.dl=		${IS_BUILTIN.dl}
.  if !empty(MACHINE_PLATFORM:MDarwin-[56].*)
USE_BUILTIN.dl=		no	# Darwin-[56].* uses devel/dlcompat
.  endif
.endif
MAKEVARS+=	USE_BUILTIN.dl

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.dl?=	no
.if !empty(CHECK_BUILTIN.dl:M[nN][oO])

.  if !empty(USE_BUILTIN.dl:M[yY][eE][sS])
BUILDLINK_PREFIX.dl=	/usr
.    if !empty(BUILTIN_LIB_FOUND.dl:M[yY][eE][sS])
#
# No need to add this to BUILDLINK_LIBS.dl since most GNU configure
# scripts already check for -ldl themselves.
#
BUILDLINK_LDADD.dl=	-ldl
.    endif
.  endif

.endif	# CHECK_BUILTIN.dl
