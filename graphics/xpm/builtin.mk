# $NetBSD: builtin.mk,v 1.15.12.1 2008/09/26 19:59:46 cube Exp $

BUILTIN_PKG:=	xpm

BUILTIN_FIND_FILES_VAR:=	H_XPM
BUILTIN_FIND_FILES.H_XPM=	${X11BASE}/include/X11/xpm.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.xpm)
IS_BUILTIN.xpm=		no
.  if empty(H_XPM:M__nonexistent__)
.    if !empty(X11BASE:M*openwin) && exists(/usr/sbin/pkgchk)
IS_BUILTIN.xpm!=							\
	if /usr/sbin/pkgchk -l SUNWxwinc 2>/dev/null | ${GREP} -q xpm.h; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.    elif ${OPSYS} == "IRIX"
IS_BUILTIN.xpm=		yes
.    elif ${OPSYS} == "Darwin"
IS_BUILTIN.xpm=		yes
.    else
BUILTIN_IMAKE_CHECK:=	xpm:NormalLibXpm
.      include "../../mk/buildlink3/imake-check.mk"
IS_BUILTIN.xpm=		${BUILTIN_IMAKE_CHECK.xpm}
.    endif
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.xpm

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.xpm) && \
    !empty(IS_BUILTIN.xpm:M[yY][eE][sS]) && \
    empty(H_XPM:M__nonexistent__)
BUILTIN_VERSION.xpm!=							\
	${AWK} 'BEGIN { split("abcdefghijklmnopqrstuvwxyz", alpha, "");	\
			p = ".0" }					\
		/\#define[ 	]*XpmFormat/ { M = $$3 }		\
		/\#define[ 	]*XpmVersion/ { m = "."$$3 }		\
		/\#define[ 	]*XpmRevision/ { p = alpha[$$3] }	\
		END { printf "%s%s%s\n", M, m, p }'			\
		${H_XPM}
BUILTIN_PKG.xpm=	xpm-${BUILTIN_VERSION.xpm}
.endif
MAKEVARS+=	BUILTIN_PKG.xpm

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.xpm)
.  if ${PREFER.xpm} == "pkgsrc"
USE_BUILTIN.xpm=	no
.  else
USE_BUILTIN.xpm=	${IS_BUILTIN.xpm}
.    if defined(BUILTIN_PKG.xpm) && \
        !empty(IS_BUILTIN.xpm:M[yY][eE][sS])
USE_BUILTIN.xpm=	yes
.      for dep in ${BUILDLINK_API_DEPENDS.xpm}
.        if !empty(USE_BUILTIN.xpm:M[yY][eE][sS])
USE_BUILTIN.xpm!=							\
	if ${PKG_ADMIN} pmatch ${dep:Q} ${BUILTIN_PKG.xpm:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.xpm
.endif
MAKEVARS+=	USE_BUILTIN.xpm

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

.include "../../mk/x11.builtin.mk"
