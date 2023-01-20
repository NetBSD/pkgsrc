# $NetBSD: builtin.mk,v 1.14 2023/01/20 13:10:08 wiz Exp $

BUILTIN_PKG:=	fontconfig

BUILTIN_FIND_FILES_VAR:=		H_FONTCONFIG
BUILTIN_FIND_FILES.H_FONTCONFIG=	\
	${X11BASE}/include/fontconfig/fontconfig.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.fontconfig)
.  if empty(H_FONTCONFIG:M__nonexistent__)
IS_BUILTIN.fontconfig=	yes
.  else
IS_BUILTIN.fontconfig=	no
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.fontconfig

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.fontconfig) && \
    ${IS_BUILTIN.fontconfig:tl} == yes && \
    empty(H_FONTCONFIG:M__nonexistent__)
BUILTIN_VERSION.fontconfig!=						\
	${AWK} '/\#define[ 	]*FC_MAJOR/ { M = $$3 }			\
		/\#define[ 	]*FC_MINOR/ { m = "."$$3 }		\
		/\#define[ 	]*FC_REVISION/ { r = "."$$3 }		\
		END { printf "%s%s%s\n", M, m, r }'			\
		${H_FONTCONFIG}
BUILTIN_PKG.fontconfig=	fontconfig-${BUILTIN_VERSION.fontconfig}
.endif
MAKEVARS+=		BUILTIN_PKG.fontconfig

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###

.if !defined(USE_BUILTIN.fontconfig)
.  if ${PREFER.fontconfig} == "pkgsrc"
USE_BUILTIN.fontconfig=	no
.  else
USE_BUILTIN.fontconfig=	${IS_BUILTIN.fontconfig}
.    if defined(BUILTIN_PKG.fontconfig) && \
        ${IS_BUILTIN.fontconfig:tl} == yes
USE_BUILTIN.fontconfig=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.fontconfig}
.        if ${USE_BUILTIN.fontconfig:tl} == yes
USE_BUILTIN.fontconfig!=						\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.fontconfig:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.fontconfig
.endif
MAKEVARS+=		USE_BUILTIN.fontconfig

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.fontconfig?=	no
.if ${CHECK_BUILTIN.fontconfig:tl} == no

.  if ${USE_BUILTIN.fontconfig:tl} == no
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.1nb2
BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.1.3
.  endif

.endif	# CHECK_BUILTIN.fontconfig
