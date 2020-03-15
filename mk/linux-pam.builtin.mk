# $NetBSD: linux-pam.builtin.mk,v 1.2 2020/03/15 23:03:03 rillig Exp $

BUILTIN_PKG:=	linux-pam

BUILTIN_FIND_HEADERS_VAR:=	H_LINUX_PAM
BUILTIN_FIND_HEADERS.H_LINUX_PAM=	security/pam_appl.h	\
				pam/pam_appl.h
BUILTIN_FIND_GREP.H_LINUX_PAM=	The Linux-PAM Framework layer API

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.linux-pam)
IS_BUILTIN.linux-pam=	no
.  if empty(H_LINUX_PAM:M__nonexistent__) && empty(H_LINUX_PAM:M${LOCALBASE}/*)
IS_BUILTIN.linux-pam=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.linux-pam

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.linux-pam)
.  if ${PREFER.linux-pam} == "pkgsrc"
USE_BUILTIN.linux-pam=	no
.  else
USE_BUILTIN.linux-pam=	${IS_BUILTIN.linux-pam}
.    if defined(BUILTIN_PKG.linux-pam) && \
        !empty(IS_BUILTIN.linux-pam:M[yY][eE][sS])
USE_BUILTIN.linux-pam=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.linux-pam}
.        if !empty(USE_BUILTIN.linux-pam:M[yY][eE][sS])
USE_BUILTIN.linux-pam!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.linux-pam:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.linux-pam
.endif
MAKEVARS+=	USE_BUILTIN.linux-pam

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.linux-pam?=	no
.if !empty(CHECK_BUILTIN.linux-pam:M[nN][oO])

.  if !empty(USE_BUILTIN.linux-pam:M[yY][eE][sS])
BUILDLINK_TARGETS+=	buildlink-pam-security
.  endif

.  if !target(buildlink-pam-security)
.PHONY: buildlink-pam-security
buildlink-pam-security:
	${RUN}								\
	src=${BUILDLINK_PREFIX.linux-pam}"/include/pam";		\
	dest=${BUILDLINK_DIR}"/include/security";			\
	if ${TEST} -d "$$src"; then					\
		${RM} -fr "$$dest";					\
		${LN} -fs "$$src" "$$dest";				\
	fi
.  endif

.endif	# CHECK_BUILTIN.linux-pam
