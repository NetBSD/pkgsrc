# $NetBSD: builtin.mk,v 1.1 2025/06/01 08:11:47 vins Exp $

BUILTIN_PKG:=	openssh

BUILTIN_FIND_FILES_VAR:=	SSH
BUILTIN_FIND_FILES.SSH=		\
	/bin/ssh 		\
	/usr/bin/ssh		\
	/usr/local/bin/ssh

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.openssh)
.  if empty(SSH:M__nonexistent__)
IS_BUILTIN.openssh=	yes
.  else
IS_BUILTIN.openssh=	no
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.openssh

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if ${USE_CROSS_COMPILE:tl} != "yes" && \
    !defined(BUILTIN_PKG.openssh) && \
    ${IS_BUILTIN.openssh:tl} == yes
BUILTIN_VERSION.openssh!=	${SSH} -V 2>&1 | sed -e 's/.*_\([0-9][0-9\.]*\).*/\1/'
BUILTIN_PKG.openssh=		openssh-${BUILTIN_VERSION.openssh}
.endif
MAKEVARS+=			BUILTIN_PKG.openssh

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.openssh)
.  if ${PREFER.openssh} == "pkgsrc"
USE_BUILTIN.openssh=	no
.  else
USE_BUILTIN.openssh=	${IS_BUILTIN.openssh}
.    if defined(BUILTIN_PKG.openssh) && \
	${IS_BUILTIN.openssh:tl} == yes
USE_BUILTIN.openssh=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.openssh}
.        if ${USE_BUILTIN.openssh:tl} == yes
USE_BUILTIN.openssh!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.openssh:Q}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.        endif
.      endfor
.    endif
.  endif
.endif
MAKEVARS+=		USE_BUILTIN.openssh
