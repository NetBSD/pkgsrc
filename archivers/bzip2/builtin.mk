# $NetBSD: builtin.mk,v 1.9 2013/11/23 10:51:09 obache Exp $

BUILTIN_PKG:=	bzip2

BUILTIN_FIND_HEADERS_VAR:=	H_BZIP2
BUILTIN_FIND_HEADERS.H_BZIP2=	bzlib.h
BUILTIN_FIND_GREP.H_BZIP2=	BZ2_

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.bzip2)
IS_BUILTIN.bzip2=	no
.  if empty(H_BZIP2:M__nonexistent__) && empty(H_BZIP2:M${LOCALBASE}/*)
IS_BUILTIN.bzip2=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.bzip2

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.bzip2) && \
    !empty(IS_BUILTIN.bzip2:M[yY][eE][sS])
BUILTIN_VERSION.bzip2!=							\
	${AWK} '/Copyright[ 	]+\(C\).*rights[ 	]+reserved/ {	\
			years=$$3;					\
		}							\
		/bzip2\/libbzip2[ 	]+version[ 	]+/ {		\
			vers=$$3;					\
			if ( vers == "1.0" ) {				\
				vers="1.0.1";				\
				if ( years == "1996-2002" ) vers="1.0.2";\
				if ( years == "1996-2005" ) vers="1.0.3";\
			};						\
			print vers;					\
		};							\
	' ${H_BZIP2:Q}

BUILTIN_PKG.bzip2=	bzip2-${BUILTIN_VERSION.bzip2}
.endif
MAKEVARS+=    BUILTIN_PKG.bzip2

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
.      for _dep_ in ${BUILDLINK_API_DEPENDS.bzip2}
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
