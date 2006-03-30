# $NetBSD: builtin.mk,v 1.9 2006/03/30 18:06:18 jlam Exp $

BUILTIN_PKG:=	pflkm

BUILTIN_FIND_FILES_VAR:=	H_PFLKM EXE_PFCTL
BUILTIN_FIND_FILES.H_PFLKM=	/usr/include/net/pfvar.h
BUILTIN_FIND_FILES.H_PFLKM+=	/usr/include/net/pf/pfvar.h
BUILTIN_FIND_FILES.EXE_PFCTL+=	/sbin/pfctl

.include "../../mk/buildlink3/bsd.builtin.mk"

# Compute the version number of the PF API by checking for the presence
# of symbols added in newer versions and store the result in ${PF_VERSION}.
#
.if !defined(PF_VERSION)
PF_VERSION=	3.7	# package default
.  if empty(H_PFLKM:M__nonexistent__)
# OpenBSD 3.8: pf_socket_lookup added
_BLTN_PF_3_8!=	${GREP} -c pf_socket_lookup ${H_PFLKM} || ${TRUE}
# OpenBSD 3.7: pf_threshold added
_BLTN_PF_3_7!=	${GREP} -c pf_threshold ${H_PFLKM} || ${TRUE}
# OpenBSD 3.6: pf_cksum_fixup added
_BLTN_PF_3_6!=	${GREP} -c pf_cksum_fixup ${H_PFLKM} || ${TRUE}

.    if ${_BLTN_PF_3_8} != "0"
PF_VERSION=	3.8
.    elif ${_BLTN_PF_3_7} != "0"
PF_VERSION=	3.7
.    elif ${_BLTN_PF_3_6} != "0"
PF_VERSION=	3.6
.    else
PF_VERSION=	3.5
.    endif
.  endif
.endif
MAKEVARS+=	PF_VERSION

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.pflkm)
IS_BUILTIN.pflkm=	no
.  if empty(H_PFLKM:M__nonexistent__) && empty(H_PFLKM:M${LOCALBASE}/*)
IS_BUILTIN.pflkm=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.pflkm

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.pflkm) && \
    !empty(IS_BUILTIN.pflkm:M[yY][eE][sS])
.  if ${PF_VERSION} == "3.8"
BUILTIN_PKG.pflkm=	pflkm-20051101	# release date for PF API 3.8
.  elif ${PF_VERSION} == "3.7"
BUILTIN_PKG.pflkm=	pflkm-20050519	# release date for PF API 3.7
.  elif ${PF_VERSION} == "3.6"
BUILTIN_PKG.pflkm=	pflkm-20041101	# release date for PF API 3.6
.  elif ${PF_VERSION} == "3.5"
BUILTIN_PKG.pflkm=	pflkm-20040501	# release date for PF API 3.5
.  else
BUILTIN_PKG.pflkm=	pflkm-20040501	# release date for PF API 3.5
.  endif
.endif
MAKEVARS+=	BUILTIN_PKG.pflkm

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.pflkm)
.  if ${PREFER.pflkm} == "pkgsrc"
USE_BUILTIN.pflkm=	no
.  else
USE_BUILTIN.pflkm=	${IS_BUILTIN.pflkm}
.    if defined(BUILTIN_PKG.pflkm) && \
        !empty(IS_BUILTIN.pflkm:M[yY][eE][sS])
USE_BUILTIN.pflkm=	yes
.      for _dep_ in ${BUILDLINK_DEPENDS.pflkm}
.        if !empty(USE_BUILTIN.pflkm:M[yY][eE][sS])
USE_BUILTIN.pflkm!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.pflkm:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.pflkm
.endif
MAKEVARS+=	USE_BUILTIN.pflkm

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.pflkm?= no
.if !empty(CHECK_BUILTIN.pflkm:M[nN][oO])

.  if !empty(USE_BUILTIN.pflkm:M[nN][oO])
PFCTL?=   	${BUILDLINK_PREFIX.pflkm}/bin/pfctl
.  else
PFCTL?=   	${EXE_PFCTL}
.  endif

.endif  # CHECK_BUILTIN.pflkm
