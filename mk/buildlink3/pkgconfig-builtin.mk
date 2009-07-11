# $NetBSD: pkgconfig-builtin.mk,v 1.5 2009/07/11 07:56:25 rillig Exp $

# This file is used to factor out a common pattern in builtin.mk files
# backed up by the existence of a pkgconfig file.
#
# Parameters:
#
# BUILTIN_PKG
#	The name of the package that is tested.
#
# PKGCONFIG_FILE.<BUILTIN_PKG>
#	The absolute path where the pkgconfig file of the native
#	implementation of the package is stored.
#
#	Example: ${X11BASE}/lib/pkgconfig/fontcacheproto.pc
#
# PKGCONFIG_BASE.<BUILTIN_PKG> (optional)
#	The base location for a native implementation of the package.
#
#	Default: ${X11BASE}
#
# BUILTIN_VERSION_SCRIPT.<BUILTIN_PKG> (optional)
#	The program that is used to extract the version number from the
#	PKGCONFIG_FILE.<BUILTIN_PKG>. The expected output is the plain
#	version number on a single line.
#
#	By defining a custom script this file can be called by a lot
#	more generic builtin.mk files.
#
#	Default: (something suitable for pkgconfig files)
# 

BUILTIN_FIND_FILES_VAR:=			FIND_FILES_${BUILTIN_PKG}
BUILTIN_FIND_FILES.FIND_FILES_${BUILTIN_PKG}=	${PKGCONFIG_FILE.${BUILTIN_PKG}}

.include "../../mk/buildlink3/bsd.builtin.mk"

.if ${PKGCONFIG_BASE.${BUILTIN_PKG}:U${X11BASE}} == ${LOCALBASE}
IS_BUILTIN.${BUILTIN_PKG}=	no
.elif !defined(IS_BUILTIN.${BUILTIN_PKG})
IS_BUILTIN.${BUILTIN_PKG}=	no
.  if empty(FIND_FILES_${BUILTIN_PKG}:M__nonexistent__)
IS_BUILTIN.${BUILTIN_PKG}=	yes
.  endif
.endif
MAKEVARS:=	${MAKEVARS} IS_BUILTIN.${BUILTIN_PKG}

.if !defined(BUILTIN_PKG.${BUILTIN_PKG}) && \
    !empty(IS_BUILTIN.${BUILTIN_PKG}:M[yY][eE][sS]) && \
    (!empty(FIND_FILES_${BUILTIN_PKG}:M*.pc) || \
     (empty(FIND_FILES_${BUILTIN_PKG}:M__nonexistent__) && \
     defined(BUILTIN_VERSION_SCRIPT.${BUILTIN_PKG})))
BUILTIN_VERSION_SCRIPT.${BUILTIN_PKG}?=	${SED} -n -e 's/Version: //p'
BUILTIN_VERSION.${BUILTIN_PKG}!= ${BUILTIN_VERSION_SCRIPT.${BUILTIN_PKG}} \
					${FIND_FILES_${BUILTIN_PKG}}
BUILTIN_PKG.${BUILTIN_PKG}:= ${BUILTIN_PKG}-${BUILTIN_VERSION.${BUILTIN_PKG}}
.endif
MAKEVARS:=      ${MAKEVARS} BUILTIN_PKG.${BUILTIN_PKG}

.if !defined(USE_BUILTIN.${BUILTIN_PKG})
.  if ${PREFER.${BUILTIN_PKG}} == "pkgsrc"
USE_BUILTIN.${BUILTIN_PKG}=	no
.  else
USE_BUILTIN.${BUILTIN_PKG}:=	${IS_BUILTIN.${BUILTIN_PKG}}
.    if defined(BUILTIN_PKG.${BUILTIN_PKG}) && \
	!empty(IS_BUILTIN.${BUILTIN_PKG}:M[Yy][Ee][Ss])
USE_BUILTIN.${BUILTIN_PKG}=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.${BUILTIN_PKG}}
.        if !empty(USE_BUILTIN.${BUILTIN_PKG}:M[Yy][Ee][Ss])
USE_BUILTIN.${BUILTIN_PKG}!= \
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.${BUILTIN_PKG}}; then \
		${ECHO} yes; \
	else \
		${ECHO} no; \
	fi
.        endif
.      endfor
.    endif
.  endif
.endif
MAKEVARS:=	${MAKEVARS} USE_BUILTIN.${BUILTIN_PKG}
