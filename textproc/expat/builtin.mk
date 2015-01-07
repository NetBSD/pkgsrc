# $NetBSD: builtin.mk,v 1.18 2015/01/07 14:26:47 ryoon Exp $

BUILTIN_PKG:=	expat

BUILTIN_FIND_HEADERS_VAR:=	H_EXPAT
BUILTIN_FIND_HEADERS.H_EXPAT=	expat.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.expat)
.  if empty(H_EXPAT:M__nonexistent__)
IS_BUILTIN.expat=	yes
.  else
IS_BUILTIN.expat=	no
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.expat

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.expat) && \
    !empty(IS_BUILTIN.expat:M[yY][eE][sS]) && \
    empty(H_EXPAT:M__nonexistent__)
BUILTIN_VERSION.expat!=							\
	${AWK} '/\#define[ 	]*XML_MAJOR_VERSION/ { M = $$3 }	\
		/\#define[ 	]*XML_MINOR_VERSION/ { m = "."$$3 }	\
		/\#define[ 	]*XML_MICRO_VERSION/ { u = "."$$3 }	\
		END { printf "%s%s%s\n", M, m, u }'			\
		${H_EXPAT}
BUILTIN_PKG.expat=	expat-${BUILTIN_VERSION.expat}
.endif
MAKEVARS+=	BUILTIN_PKG.expat

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.expat)
.  if ${PREFER.expat} == "pkgsrc"
USE_BUILTIN.expat=	no
.  else
USE_BUILTIN.expat=	${IS_BUILTIN.expat}
.    if defined(BUILTIN_PKG.expat) && \
        !empty(IS_BUILTIN.expat:M[yY][eE][sS])
USE_BUILTIN.expat=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.expat}
.        if !empty(USE_BUILTIN.expat:M[yY][eE][sS])
USE_BUILTIN.expat!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.expat:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.expat
.endif
MAKEVARS+=	USE_BUILTIN.expat

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.expat?=	no
.if !empty(CHECK_BUILTIN.expat:M[nN][oO])

.  if !empty(USE_BUILTIN.expat:M[nN][oO])
BUILDLINK_API_DEPENDS.expat+=	expat>=1.95.4
.  else
.    if !empty(H_EXPAT:M${X11BASE}/*)
.      include "../../mk/x11.builtin.mk"
.    elif !empty(H_EXPAT:M/usr/*)
BUILDLINK_PREFIX.expat=	/usr
.    elif !empty(H_EXPAT:M/boot/common/*)
BUILDLINK_PREFIX.expat=	/boot/common
.    endif
.  endif

.endif	# CHECK_BUILTIN.expat

# Fake pkg-config for builtin expat on NetBSD

.if !empty(USE_BUILTIN.expat:M[yY][eE][sS])
.  if !empty(USE_TOOLS:C/:.*//:Mpkg-config)
do-configure-pre-hook: override-expat-pkgconfig

BLKDIR_PKGCFG=	${BUILDLINK_DIR}/lib/pkgconfig
EXPAT_PKGCFGF=	expat.pc

override-expat-pkgconfig: override-message-expat-pkgconfig
override-message-expat-pkgconfig:
	@${STEP_MSG} "Magical transformations for expat on NetBSD."

override-expat-pkgconfig:
	${RUN}						\
	${MKDIR} ${BLKDIR_PKGCFG};			\
	{						\
	${ECHO} "prefix=${BUILDLINK_PREFIX.expat}";		\
	${ECHO} "exec_prefix=\$${prefix}";		\
	${ECHO} "libdir=\$${exec_prefix}/lib";		\
	${ECHO} "includedir=\$${prefix}/include";	\
	${ECHO} "";					\
	${ECHO} "Name: expat";				\
	${ECHO} "Description: expat XML parser";	\
	${ECHO} "Version: ${BUILTIN_VERSION.expat}";	\
	${ECHO} "Libs: ${COMPILER_RPATH_FLAG}\$${libdir} -L\$${libdir} -lexpat";	\
	${ECHO} "Cflags: -I\$${includedir}";		\
	} >> ${BLKDIR_PKGCFG}/${EXPAT_PKGCFGF};
.  endif
.endif
