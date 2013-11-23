# $NetBSD: builtin.mk,v 1.5 2013/11/23 10:51:09 obache Exp $

BUILTIN_PKG:=	libarchive

BUILTIN_FIND_HEADERS_VAR:=	H_ARCHIVE
BUILTIN_FIND_HEADERS.H_ARCHIVE=	archive.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.libarchive)
IS_BUILTIN.libarchive=	no
.  if empty(H_ARCHIVE:M__nonexistent__) && empty(H_ARCHIVE:M${LOCALBASE}/*)
IS_BUILTIN.libarchive=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.libarchive

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.libarchive) && \
    !empty(IS_BUILTIN.libarchive:M[yY][eE][sS]) && \
    empty(H_ARCHIVE:M__nonexistent__)
BUILTIN_VERSION.libarchive!=						\
	${AWK} '/\#define[ 	]*ARCHIVE_LIBRARY_VERSION/ {		\
			lib_vers = $$4;					\
			gsub("\"", "", lib_vers);			\
			if (found == 0)					\
			    found=1;					\
		}							\
		/\#define[ 	]*ARCHIVE_VERSION_STRING/ {		\
			vers_str = $$4;					\
			gsub("\"", "", vers_str);			\
			found=2;					\
		}							\
		END {							\
			if (!found)					\
				print;					\
			else if (found == 1)				\
				print lib_vers;				\
			else if (found == 2)				\
				print vers_str;				\
		}							\
	' ${H_ARCHIVE:Q}
.  if !empty(BUILTIN_VERSION.libarchive)
BUILTIN_PKG.libarchive=	libarchive-${BUILTIN_VERSION.libarchive}
.  else
IS_BUILTIN.libarchive=	no
.  endif
.endif
MAKEVARS+=	BUILTIN_PKG.libarchive

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.libarchive)
.  if ${PREFER.libarchive} == "pkgsrc"
USE_BUILTIN.libarchive=	no
.  else
USE_BUILTIN.libarchive=	${IS_BUILTIN.libarchive}
.    if defined(BUILTIN_PKG.libarchive) && \
        !empty(IS_BUILTIN.libarchive:M[yY][eE][sS])
USE_BUILTIN.libarchive=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.libarchive}
.        if !empty(USE_BUILTIN.libarchive:M[yY][eE][sS])
USE_BUILTIN.libarchive!=	\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.libarchive:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.libarchive
.endif
MAKEVARS+=	USE_BUILTIN.libarchive
