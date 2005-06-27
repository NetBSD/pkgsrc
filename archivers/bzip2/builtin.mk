# $NetBSD: builtin.mk,v 1.4 2005/06/27 18:17:57 minskim Exp $

BUILTIN_PKG:=	bzip2

BUILTIN_FIND_FILES_VAR:=	H_BZIP2
BUILTIN_FIND_FILES.H_BZIP2=	/usr/include/bzlib.h
BUILTIN_FIND_GREP.H_BZIP2=	BZ2_

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.bzip2)
IS_BUILTIN.bzip2=	no
.  if empty(H_BZIP2:M${LOCALBASE}/*) && exists(${H_BZIP2})
IS_BUILTIN.bzip2=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.bzip2

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.bzip2)
.  if ${PREFER.bzip2} == "pkgsrc"
USE_BUILTIN.bzip2=	no
.  else
USE_BUILTIN.bzip2=	${IS_BUILTIN.bzip2}
.    if defined(BUILTIN_PKG.bzip2) && \
        !empty(IS_BUILTIN.bzip2:M[yY][eE][sS])
USE_BUILTIN.bzip2=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.bzip2}
.        if !empty(USE_BUILTIN.bzip2:M[yY][eE][sS])
USE_BUILTIN.bzip2!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.bzip2:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
#
# Some platforms don't have a bzip2 implementation that can replace
# pkgsrc bzip2.
#
_INCOMPAT_BZIP2?=	SunOS-5.[678]-* Darwin-[567].*-*
.    for _pattern_ in ${_INCOMPAT_BZIP2} ${INCOMPAT_BZIP2}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.bzip2=	no
.      endif
.    endfor
.  endif  # PREFER.bzip2
.endif
MAKEVARS+=	USE_BUILTIN.bzip2

# if USE_BZIP2 is defined, then force the use of a true bzip2
# implementation.
#
.if defined(USE_BZIP2)
.  if !empty(IS_BUILTIN.bzip2:M[nN][oO])
USE_BUILTIN.bzip2=	no
.  endif
.endif
