# $NetBSD: builtin.mk,v 1.2 2005/06/01 18:03:08 jlam Exp $

BUILTIN_PKG:=	netbsd-tap

BUILTIN_FIND_FILES_VAR:=		H_NETBSD_TAP
BUILTIN_FIND_FILES.H_NETBSD_TAP=	/usr/include/net/if_tap.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.netbsd-tap)
IS_BUILTIN.netbsd-tap=	no
. if empty(H_NETBSD_TAP:M${LOCALBASE}/*) && exists(${H_NETBSD_TAP})
IS_BUILTIN.netbsd-tap=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.netbsd-tap

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.netbsd-tap)
.  if ${PREFER.netbsd-tap} == "pkgsrc"
USE_BUILTIN.netbsd-tap=	no
.  else
USE_BUILTIN.netbsd-tap=	${IS_BUILTIN.netbsd-tap}
.    if defined(BUILTIN_PKG.netbsd-tap) && \
        !empty(IS_BUILTIN.netbsd-tap:M[yY][eE][sS])
USE_BUILTIN.netbsd-tap=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.netbsd-tap}
.        if !empty(USE_BUILTIN.netbsd-tap:M[yY][eE][sS])
USE_BUILTIN.netbsd-tap!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.netbsd-tap:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.netbsd-tap
.endif
MAKEVARS+=	USE_BUILTIN.netbsd-tap
