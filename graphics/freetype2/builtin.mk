# $NetBSD: builtin.mk,v 1.20 2023/02/09 19:49:45 wiz Exp $

BUILTIN_PKG:=	freetype2

BUILTIN_FIND_FILES_VAR:=		H_FREETYPE2 H_FREETYPE2_NEW
BUILTIN_FIND_FILES.H_FREETYPE2=		${X11BASE}/include/freetype2/freetype/freetype.h
BUILTIN_FIND_FILES.H_FREETYPE2_NEW=	${X11BASE}/include/freetype2/freetype.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.freetype2)
.  if empty(H_FREETYPE2:M__nonexistent__)
IS_BUILTIN.freetype2=	yes
.  elif empty(H_FREETYPE2_NEW:M__nonexistent__)
IS_BUILTIN.freetype2=	yes
H_FREETYPE2:=		${H_FREETYPE2_NEW}
.  else
IS_BUILTIN.freetype2=	no
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.freetype2

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.freetype2) && \
    ${IS_BUILTIN.freetype2:tl} == yes && \
    empty(H_FREETYPE2:M__nonexistent__)
BUILTIN_VERSION.freetype2!=						\
	${AWK} 'BEGIN { p = ".0" }					\
		/\#define[ 	]*FREETYPE_MAJOR/ { M = $$3 }		\
		/\#define[ 	]*FREETYPE_MINOR/ { m = "."$$3 }	\
		/\#define[ 	]*FREETYPE_PATCH/ { p = "."$$3 }	\
		END { printf "%s%s%s\n", M, m, p }'			\
		${H_FREETYPE2}
BUILTIN_PKG.freetype2=	freetype2-${BUILTIN_VERSION.freetype2}
.endif
MAKEVARS+=		BUILTIN_PKG.freetype2

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.freetype2)
.  if ${PREFER.freetype2} == "pkgsrc"
USE_BUILTIN.freetype2=	no
.  else
USE_BUILTIN.freetype2=	${IS_BUILTIN.freetype2}
.    if defined(BUILTIN_PKG.freetype2) && \
        ${IS_BUILTIN.freetype2:tl} == yes
USE_BUILTIN.freetype2=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.freetype2}
.        if ${USE_BUILTIN.freetype2:tl} == yes
USE_BUILTIN.freetype2!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.freetype2}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.freetype2
.endif
MAKEVARS+=		USE_BUILTIN.freetype2

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

.include "../../mk/x11.builtin.mk"

CHECK_BUILTIN.freetype2?=	no
.if ${CHECK_BUILTIN.freetype2:tl} == no

.  if ${USE_BUILTIN.freetype2:tl} == no
BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.1.3
.  else
.    if !empty(MACHINE_PLATFORM:MNetBSD-[67].*-*) && \
	(("${BUILTIN_VERSION.freetype2}" == "2.4.5") || \
	("${BUILTIN_VERSION.freetype2}" == "2.5.3"))
_FT2_VER_MAP.2.5.3=			17.2.11
_FT2_VER_MAP.2.4.5=			13.0.7
SUBST_CLASSES+=				fx-ft2-pc-version
SUBST_STAGE.fx-ft2-pc-version=		post-wrapper
SUBST_MESSAGE.fx-ft2-pc-version=	Fixes wrong module version in freetype2.pc
SUBST_FILES.fx-ft2-pc-version=		${BUILDLINK_X11_DIR}/lib/pkgconfig/freetype2.pc
SUBST_SED.fx-ft2-pc-version=		-e 's|^\(Version:\).*|\1 ${_FT2_VER_MAP.${BUILTIN_VERSION.freetype2}}|'
.    endif
.  endif

.endif	# CHECK_BUILTIN.freetype2
